import sys
import os
import select 
import socket
from socket_server import SocketServer
from argument import parse_argument
from time import sleep

def check_food():
    print "check food"

def find_rock():
    print "find rock"

def send_ok(so):
    check_food()
    find_rock()
    print "send OK"

def read_ok(so):
    print "read OK"

def begin_select(so):
    while 1:
        inputready,outputready,exceptready = select.select([so.fd_socket],[so.fd_socket],[])
        for i in inputready:
            if i == so.fd_socket:
                read_ok(so)
        for j in outputready:
            if j == so.fd_socket:
                send_ok(so)
