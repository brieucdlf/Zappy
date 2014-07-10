import sys
import os
import select 
import socket
from moving import *
from socket_server import SocketServer
from argument import parse_argument
from time import sleep

request = []
player = {
    "inventaire" : {},
    "lvl" : 1,
    "what_i_see" : {},
    "target_pos" : 0,
    "path" : []
}

def find_player(so):
    i = 0
    j = 0
    print "ROMAIN"
    so.send_request("voir\n")
    data = so.read_request()
    data = data.replace('{', '')
    data = data.replace('}', '')
    data = data.replace('\n', '')
    data = data.split(", ")
    for item in data:
        player["what_i_see"][i] = data[i].split(" ")
        i = i + 1
    #print player["what_i_see"]
    for key in player["what_i_see"]:
        for key2 in player["what_i_see"][key]:
            if player["what_i_see"][key][0] == "nourriture":
                so.send_request("prend nourriture\n")
                print "nourriture"
            j = j + 1
        j = 0

def get_inventaire(data):
    i = 0
    case_of_nb = 0
    print "inventaire"
    data = data.rstrip('{')
    data = data.rstrip('}')
    data = data.rstrip('\n')
    data = data.split(", ")
    item_name = []
    item_nb = []
    for i in range(0, len(data)):
        item_name.append(data[i].split(' ')[0])
    for j in range(0, len(data)):
        item_nb.append(data[j].split(' ')[1])
    for key in item_name:
        player["inventaire"][key] = item_nb[case_of_nb]
        case_of_nb = case_of_nb + 1
    print player["inventaire"]
    request.remove(request[0])

def test_incantation(so):
    if player["lvl"] == 1:
        if 'linemate' in player["inventaire"] and player["inventaire"]["linemate"] == 1 \
        and "deraumere" in player["inventaire"] and player["inventaire"]["deraumere"] == 0 \
        and "sibur" in player["inventaire"] and player["inventaire"]["sibur"] == 0 \
        and "mendiane" in player["inventaire"] and player["inventaire"]["mendiane"] == 0 \
        and "phiras" in player["inventaire"] and player["inventaire"]["phiras"] == 0 \
        and "thystane" in player["inventaire"] and player["inventaire"]["thystane"] == 0:
            if find_player(so) == 1:
                return drop_rocks()
    find_player(so)
    return True

def find_excedent():
    tab = []
    if player["lvl"] == 1:
        if 'linemate' in player["inventaire"] and player["inventaire"]["linemate"] > 1:
            tab.append("linemate")
        if "deraumere" in player["inventaire"] and player["inventaire"]["deraumere"] > 0:
            tab.append("deraumere")
        if "sibur" in player["inventaire"] and player["inventaire"]["sibur"] > 0:
            tab.append("sibur")
        if "mendiane" in player["inventaire"] and player["inventaire"]["mendiane"] > 0:
            tab.append("mendiane")
        if "phiras" in player["inventaire"] and player["inventaire"]["phiras"] > 0:
            tab.append("phiras")
        if "thystane" in player["inventaire"] and player["inventaire"]["thystane"] > 0:
            tab.append("thystane")
    elif player["lvl"] == 2:
        if "linemate" in player["inventaire"] and player["inventaire"]["linemate"] > 1:
            tab.append("linemate")
        if "deraumere" in player["inventaire"] and player["inventaire"]["deraumere"] > 1:
            tab.append("deraumere")
        if "sibur" in player["inventaire"] and player["inventaire"]["sibur"] > 1:
            tab.append("sibur")
        if "mendiane" in player["inventaire"] and player["inventaire"]["mendiane"] > 0:
            tab.append("mendiane")
        if "phiras" in player["inventaire"] and player["inventaire"]["phiras"] > 0:
            tab.append("phiras")
        if "thystane" in player["inventaire"] and player["inventaire"]["thystane"] > 0:
            tab.append("thystane")
    elif player["lvl"] == 3:
        if "linemate" in player["inventaire"] and player["inventaire"]["linemate"] > 2:
            tab.append("linemate")
        if "deraumere" in player["inventaire"] and player["inventaire"]["deraumere"] > 0:
            tab.append("deraumere")
        if "sibur" in player["inventaire"] and player["inventaire"]["sibur"] > 1:
            tab.append("sibur")
        if "mendiane" in player["inventaire"] and player["inventaire"]["mendiane"] > 0:
            tab.append("mendiane")
        if "phiras" in player["inventaire"] and player["inventaire"]["phiras"] > 2:
            tab.append("phiras")
        if "thystane" in player["inventaire"] and player["inventaire"]["thystane"] > 0:
            tab.append("thystane")
    elif player["lvl"] == 4:
        if "linemate" in player["inventaire"] and player["inventaire"]["linemate"] > 1:
            tab.append("linemate")
        if "deraumere" in player["inventaire"] and player["inventaire"]["deraumere"] > 1:
            tab.append("deraumere")
        if "sibur" in player["inventaire"] and player["inventaire"]["sibur"] > 2:
            tab.append("sibur")
        if "mendiane" in player["inventaire"] and player["inventaire"]["mendiane"] > 0:
            tab.append("mendiane")
        if "phiras" in player["inventaire"] and player["inventaire"]["phiras"] > 1:
            tab.append("phiras")
        if "thystane" in player["inventaire"] and player["inventaire"]["thystane"] > 0:
            tab.append("thystane")
    return tab

def what_i_need():
    return "voir\n"

def what_i_see(data):
    return

def main_loop(so):
    while 1:
        if player["inventaire"] == {}:
            command = "inventaire\n"
        elif test_incantation(so):
            command = "incantation\n"
        else:
            drop = find_excedent()
            for key in drop:
                so.send_request("pose " + key + "\n")
                data = so.read_request()
                player["inventaire"][key] = int(player["inventaire"][key]) - 1
            command = what_i_need()
        request.append(command)
        so.send_request(command)
        data = so.read_request()
        if command == "inventaire\n":
            get_inventaire(data)
        if command == "incantation\n":
            if "niveau actuel : " in data:
                player["lvl"] = player["lvl"] + 1
        if command == "voir\n":
            what_i_see(data)
        if "prend " in command and data == "ok\n":
            player["inventaire"] = {};
        sleep(1)
