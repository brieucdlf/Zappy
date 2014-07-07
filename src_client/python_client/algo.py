import sys
import os
import select 
import socket
from socket_server import SocketServer
from argument import parse_argument
from time import sleep

def begin_select():
    inputready,outputready,exceptready = select.select(input,[],[])
