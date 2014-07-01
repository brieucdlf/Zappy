import sys
import os
from socket_server import SocketServer
from argument import parse_argument
from time import sleep

def connect_socket(argument):
    so = SocketServer(argument["ip"], argument["port"])
    if so.connect_server() == False:
        print ("Error connexion to server ip:[{0}] port:[{1}]".format(argument["ip"], argument["port"]))
        exit(1)
    return so

def main(argv):
    config_server = {}
    config_server = parse_argument(argv)
    so = connect_socket(config_server)
    so.read_request()

    so.send_request("voir\n")
    sleep(2)

if __name__ == "__main__":    
    main(sys.argv)
