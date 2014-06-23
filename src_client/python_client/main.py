import sys
import os
from socket_server import SocketServer
from argument import parse_argument

def connect_socket(argument):
    so = SocketServer(argument["ip"], argument["port"])
    if so.connect_server() == True:
        so.send_request("salut\n")
    else:
        print("Error creation socket")

def main(argv):
    config_server = {}
    config_server = parse_argument(argv).__dict__
    connect_socket(config_server)
    
if __name__ == "__main__":
    main(sys.argv)
