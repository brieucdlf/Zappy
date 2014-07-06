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
    infos = {
        "num_client" : [],
        "x_y" : [],
    }
    config_server = {}
    config_server = parse_argument(argv)
    so = connect_socket(config_server)
    # if so.read_request() != "Bienvenue\n":
    #     print "TOTO"
    print so.read_request() 
    so.send_request("team4\n")
    num_client = int(so.read_request())
    if num_client >= 1:
        infos["num_client"] = num_client
    else:
        return
    print "num client in dict : " + str(infos["num_client"])
    coord = so.read_request().split(" ")
    if len(coord) != 2:
        return
    else:
        infos["x_y"].append(int(coord[0]))
        infos["x_y"].append(int(coord[1]))
    print infos["x_y"]
    while (1):
        pass

if __name__ == "__main__":    
    main(sys.argv)
