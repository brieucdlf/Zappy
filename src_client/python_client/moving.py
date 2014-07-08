import sys
import os
import select 
import socket
import read

def make_path(pos): #enregistre chaque mouvement pour chaque position
    if pos == 1:
        read.player["path"] = ["avance\n", "gauche\n"]
    elif pos == 2:
        read.player["path"] = ["avance\n"]
    elif pos == 3:
        read.player["path"] = ["avance\n", "droite\n"]
    elif pos == 4:
        read.player["path"] = ["avance\n"], ["avance\n"], ["gauche\n"], ["gauche\n"]
    elif pos == 5:
        read.player["path"] = ["avance\n"], ["avance\n"], ["gauche\n"]
    elif pos == 6:
        read.player["path"] = ["avance\n"], ["avance\n"]
    elif pos == 7:
        read.player["path"] = ["avance\n"], ["avance\n"], ["droite\n"]
    elif pos == 8:
        read.player["path"] = ["avance\n"], ["avance\n"], ["droite\n"], ["droite\n"]
    elif pos == 9:
        read.player["path"] = ["avance\n"], ["avance\n"], ["avance\n"], ["gauche\n"], ["gauche\n"], ["gauche\n"]
    elif pos == 10:
        read.player["path"] = ["avance\n"], ["avance\n"], ["avance\n"], ["gauche\n"], ["gauche\n"]
    elif pos == 11:
        read.player["path"] = ["avance\n"], ["avance\n"], ["avance\n"], ["gauche\n"]
    elif pos == 12:
        read.player["path"] = ["avance\n"], ["avance\n"], ["avance\n"]
    elif pos == 13:
        read.player["path"] = ["avance\n"], ["avance\n"], ["avance\n"], ["droite\n"]
    elif pos == 14:
        read.player["path"] = ["avance\n"], ["avance\n"], ["avance\n"], ["droite\n"], ["droite\n"]
    elif pos == 15:
        read.player["path"] = ["avance\n"], ["avance\n"], ["avance\n"], ["droite\n"], ["droite\n"], ["droite\n"]

def make_deplacement(so): #Fonction qui deplace l'ia j'usqu'a sa cible
    if read.player["path"] != []:
        for key in read.player["path"]:
            so.send_request(key)
            print key
        read.player["path"] = []
    else:
        print "PAS DE MOUVEMENTS DANS LISTE"
        if read.player["flag_nourriture"] == 1:
            so.send_request("prend nourriture\n")
            print "PREND NOURRITURE"
            read.request.append("prend nourriture\n")
        read.player["flag_nourriture"] = 0
        print "Deplacement termines"
        read.player["flag_voir"] = 1
