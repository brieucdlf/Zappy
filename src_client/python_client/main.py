import sys
import os
from socket_server import SocketServer

def main(argv):
    so = SocketServer("127.0.0.1", 65510)
    if so.connect_server() == True:
        so.send_request("salut\n")
    else:
        print "Error creation socket"
    
if __name__ == "__main__":
    main(sys.argv)
