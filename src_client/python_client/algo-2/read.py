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

def drop_rocks(so):
    i = 0
    so.send_request("voir\n")
    data = so.read_request()
    data = data.replace('{', '')
    data = data.replace('}', '')
    data = data.replace('\n', '')
    data = data.split(", ")
    for item in data:
        player["what_i_see"][i] = data[i].split(" ")
        i = i + 1
    for key in player["what_i_see"]:
        for key2 in player["what_i_see"][key]:
            if key2 == "joueur":
                if key == 0:
                    to_drop = player["inventaire"].keys()
                    for item in player["inventaire"]:
                        if to_drop != "nourriture":
                            for item2 in to_drop:
                                so.send_request("pose " + item2 + "\n")
                                data = so.read_request()
                    return True
                else:
                    return False
    return False

def find_player(so):
    i = 0
    compt = 0
    so.send_request("voir\n")
    data = so.read_request()
    data = data.replace('{', '')
    data = data.replace('}', '')
    data = data.replace('\n', '')
    data = data.split(", ")
    for item in data:
        player["what_i_see"][i] = data[i].split(" ")
        i = i + 1
    for key in player["what_i_see"][0]:
        if key == "nourriture":
            so.send_request("prend nourriture\n")
            print "nourriture"
        if key != "linemate" and key != "deraumere" and key != "sibur" and key != "mendiane" \
        and key != "phiras" and key != "thystame" and key != "nourriture" and key != "":
            compt = compt + 1
    return compt

def get_inventaire(data):
    i = 0
    case_of_nb = 0
    print "inventaire"
    data = data.replace('{', '')
    data = data.replace('}', '')
    data = data.replace('\n', '')
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

def test_incantation(so):
    if player["lvl"] == 1:
        if 'linemate' in player["inventaire"] and player["inventaire"]["linemate"] == 1 \
        and "deraumere" in player["inventaire"] and player["inventaire"]["deraumere"] == 0 \
        and "sibur" in player["inventaire"] and player["inventaire"]["sibur"] == 0 \
        and "mendiane" in player["inventaire"] and player["inventaire"]["mendiane"] == 0 \
        and "phiras" in player["inventaire"] and player["inventaire"]["phiras"] == 0 \
        and "thystane" in player["inventaire"] and player["inventaire"]["thystane"] == 0:
            if find_player(so) == 1:
                return drop_rocks(so)
    elif player["lvl"] == 2:
        if 'linemate' in player["inventaire"] and player["inventaire"]["linemate"] == 1 \
        and "deraumere" in player["inventaire"] and player["inventaire"]["deraumere"] == 1 \
        and "sibur" in player["inventaire"] and player["inventaire"]["sibur"] == 1 \
        and "mendiane" in player["inventaire"] and player["inventaire"]["mendiane"] == 0 \
        and "phiras" in player["inventaire"] and player["inventaire"]["phiras"] == 0 \
        and "thystane" in player["inventaire"] and player["inventaire"]["thystane"] == 0:
            if find_player(so) == 2:
                return drop_rocks(so)
    elif player["lvl"] == 3:
        if 'linemate' in player["inventaire"] and player["inventaire"]["linemate"] == 2 \
        and "deraumere" in player["inventaire"] and player["inventaire"]["deraumere"] == 0 \
        and "sibur" in player["inventaire"] and player["inventaire"]["sibur"] == 1 \
        and "mendiane" in player["inventaire"] and player["inventaire"]["mendiane"] == 0 \
        and "phiras" in player["inventaire"] and player["inventaire"]["phiras"] == 2 \
        and "thystane" in player["inventaire"] and player["inventaire"]["thystane"] == 0:
            if find_player(so) == 2:
                return drop_rocks(so)
    elif player["lvl"] == 4:
        if 'linemate' in player["inventaire"] and player["inventaire"]["linemate"] == 1 \
        and "deraumere" in player["inventaire"] and player["inventaire"]["deraumere"] == 1 \
        and "sibur" in player["inventaire"] and player["inventaire"]["sibur"] == 2 \
        and "mendiane" in player["inventaire"] and player["inventaire"]["mendiane"] == 0 \
        and "phiras" in player["inventaire"] and player["inventaire"]["phiras"] == 1 \
        and "thystane" in player["inventaire"] and player["inventaire"]["thystane"] == 0:
            if find_player(so) == 4:
                return drop_rocks(so)
    else:
        print "Error with lvl"
    return False

def find_excedent(so):
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
    drop_rocks(so)
    return tab

def what_i_need(so):
    tab = []
    if player["lvl"] == 1:
        if find_player(so) < 1:
            tab = "player"
        if player["inventaire"]["linemate"] < 1:
            tab = "linemate"
    elif player["lvl"] == 2:
        if find_player(so) < 2:
            tab = "player"
        if player["inventaire"]["linemate"] < 1:
            tab = "linemate"
        if player["inventaire"]["deraumere"] < 1:
            tab = "deraumere"
        if player["inventaire"]["sibur"] < 1:
            tab = "sibur"
    elif player["lvl"] == 3:
        if find_player(so) < 2:
            tab = "player"
        if player["inventaire"]["linemate"] < 2:
            tab = "linemate"
        if player["inventaire"]["sibur"] < 1:
            tab = "sibur"
        if player["inventaire"]["phiras"] < 2:
            tab = "phiras"
    elif player["lvl"] == 4:
        if find_player(so) < 4:
            tab = "player"
        if player["inventaire"]["linemate"] < 1:
            tab = "linemate"
        if player["inventaire"]["deraumere"] < 1:
            tab = "deraumere"
        if player["inventaire"]["sibur"] < 1:
            tab = "sibur"
        if player["inventaire"]["mendiane"] < 3:
            tab = "mendiane"
    else:
        print "Error with lvl"
    so.send_request("voir\n")
    data = so.read_request()
    return moving(data, tab)

def moving(data, tab):
    i = 0
    data = data.replace('{', '')
    data = data.replace('}', '')
    data = data.replace('\n', '')
    data = data.split(", ")
    for item in data:
        player["what_i_see"][i] = data[i].split(" ")
        i = i + 1
    print request
    if request == "droite\n" or request == "gauche\n":
        return "avance\n"
    for key in player["what_i_see"]:
        for key2 in player["what_i_see"][key]:
            if key2 == tab:
                if key == 0:
                    return "prend " + tab + "\n"
                elif key == 2 or key == 6 or key == 12 or key == 20 or key == 30:
                    return "avance\n"
                elif key == 3 or (key > 6 and key < 9) or (key > 12 and key < 16) or (key > 20 and key < 25) \
                or (key > 30 and key < 36):
                    return "droite\n"
                return "gauche\n"
    return "avance\n"

def main_loop(so):
    while 1:
        if player["inventaire"] == {}:
            command = "inventaire\n"
        elif test_incantation(so):
            command = "incantation\n"
        else:
            drop = find_excedent(so)
            for key in drop:
                so.send_request("pose " + key + "\n")
                data = so.read_request()
                player["inventaire"][key] = int(player["inventaire"][key]) - 1
            command = what_i_need(so)
            global request
            request = command
            print request
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
