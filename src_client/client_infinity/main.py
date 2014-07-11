import sys
import os
from socket_server import SocketServer
from argument import parse_argument
from time import sleep
import random
import signal

command = ["voir\n", "broadcast salut\n", "prend sibur\n",  "pose sibur\n", "broadcast dfsfdksfsldkfjdsklfjdsklfksd\n", "avance\n", "gauche\n", "droite\n", "voir\n", "prend nourriture\n", "prend sibur\n", "pose sibur\n", "pose mendiane\n", "pose thystame\n", "prend linemate\n", "prend deraumere\n", "pose linemate\n", "pose deraumere\n"]

def connect_socket(argument):
    so = SocketServer(argument["ip"], argument["port"])
    if so.connect_server() == False:
        print ("Error connexion to server ip:[{0}] port:[{1}]".format(argument["ip"], argument["port"]))
        exit(1)
    return so

def handle_signal_pipe():
    print("sigpipae")

def set_server(so, infos):
    # if so.read_request() != "Bienvenue\n":
    #     print "TOTO"
    print so.read_request() 
    so.send_request("team4\n")
    so.read_request()
    print "num client in dict : " + str(infos["num_client"])
    coord = so.read_request().split(" ")
    if len(coord) != 2:
        return
    else:
        infos["x_y"].append(int(coord[0]))
        infos["x_y"].append(int(coord[1]))
    print infos["x_y"]

    #signal.signal(signal.SIGPIPE, handle_signal_pipe)

    while 1:
        try:
            task = random.choice(command)
            so.send_request(task)
            print(so.read_request())
        except:
            print("Error pipe")
            exit(0)

def main(argv):
    infos = {
        "num_client" : [],
        "x_y" : [],
    }
    config_server = {}
    config_server = parse_argument(argv)
    so = connect_socket(config_server)
    set_server(so, infos)

if __name__ == "__main__":    
    main(sys.argv)
