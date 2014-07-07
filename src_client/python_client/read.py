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
    "what_i_see" : {},
    "target_pos" : 0
}

def check_voir(so):
    so.send_request("voir\n")
    request.append("voir\n")
    player["flag_voir"] = 0
    print "WRITE VOIR OK"
    
def check_food(so):
    i = 0
    if len(player["what_i_see"]) != 0:
        for key in player["what_i_see"]:
            for item in player["what_i_see"][key]:
                if player["what_i_see"][key][i] == "nourriture":
                    print "food found"
                    print player["what_i_see"][key].index(player["what_i_see"][key][i]) #J'affiche la position de la nourriture
                    player["target_pos"] = player["what_i_see"][key].index(player["what_i_see"][key][i]) #Je set la position ou le joueur doit se diriger
                    return
                i = i + 1
            i = 0
        print "check food"
    return

# def find_rock():
#     print "find rock"

def send_ok(so):
    if player["flag_voir"] == 1:
        check_voir(so)
        player["flag_voir"] = 0
    else:
        check_food(so)
    print "SEND COMMAND OK"

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
    elif request[0] == "inventaire\n":  #je rempli l'inventaire en local
        print "inventaire"
        test = "deraumere,nourriture,nourriture,nourriture" #chaine de test
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
                send_ok(so)
        for i in inputready:
            if i == so.fd_socket:
                read_ok(so)
        sleep(5)
