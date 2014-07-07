import sys
import os
import select 
import socket
from socket_server import SocketServer
from argument import parse_argument
from time import sleep

request = []
player = {
    "inventaire" : [],
    "lvl" : 1,
    "flag_voir" : 1,
    "what_i_see" : {}
}

def check_voir(so):
    if player["flag_voir"] == 1:
        so.send_request("voir\n")
        request.append("voir\n")
        player["flag_voir"] = 0
        print "VOIR OK"
        return 1
    return 0
    
# # def check_food(so):
# #     so.send_request("inventaire\n")
# #     request.append("inventaire\n")
# #     print "check food"
# #     return

# def find_rock():
#     print "find rock"

def send_ok(so):
    if check_voir(so) == 1:
        return
    # check_food(so)
    print "send OK"

def read_ok(so):
    i = 0
    print "READ OK"
    request.append("incantation\n")
    if request[0] == "avance\n":
        if so.read_request() == "ok\n":
            print "avance\n"
            request.remove(request[0])
        else:
            return
    elif request[0] == "droite\n":
        if so.read_request() == "ok\n":
            print "droite\n"
            request.remove(request[0])
        else:
            return
    elif request[0] == "gauche\n":
        if so.read_request() == "ok\n":
            print "gauche\n"
            request.remove(request[0])
        else:
            return
    elif request[0] == "voir\n":
        print "voir\n"
        test = "{thystame nourriture,nourriture,thystame}"
        tmp  = test[1:-1].split(",")
        for item in tmp:
            player["what_i_see"][i] = tmp[i].split(" ")
            i = i + 1
        print player["what_i_see"]
        request.remove(request[0])
    elif request[0] == "inventaire\n":
        print "inventaire"
        test = "deraumere,nourriture,nourriture,nourriture"
        player["inventaire"] = test.split(",")
        print player["inventaire"]
        request.remove(request[0])
    elif request[0] == "prend objet\n":
        if so.read_request() == "ok\n":
            print "prend objet\n"
            request.remove(request[0])
        else:
            return
    elif request[0] == "pose objet\n":
        if so.read_request() == "ok\n":
            print "pose objet\n"
            request.remove(request[0])
        else:
            return
    elif request[0] == "broadcast\n":
        if so.read_request() == "ok\n":
            print "broadcast\n"
            request.remove(request[0])
        else:
            return
    elif request[0] == "incantation\n":
        test = "lol 5"
        player["lvl"] = int(test[-1])
        request.remove(request[0])
    else:
        return

def begin_select(so):
    while 1:
        inputready,outputready,exceptready = select.select([so.fd_socket],[so.fd_socket],[])
        for j in outputready:
            if j == so.fd_socket:
                if player["flag_voir"] == 1:
                    print "SEND OK"
                    send_ok(so)
        for i in inputready:
            if i == so.fd_socket:
                read_ok(so)
                return
