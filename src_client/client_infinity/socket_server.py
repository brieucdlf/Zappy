import socket
import os

class SocketServer:
    __ip_address = None
    __port = None
    __socket_server = None
    __fd_socket = 0

    def __init__(self, ip_address, port):
        self.__ip_address = ip_address
        self.__port = port

    def send_request(self, msg):
        os.write(self.__socket_server.fileno(), msg)

    def read_request(self):
        return os.read(self.__socket_server.fileno(), 10000)
    def connect_server(self):
        try:
            self.__socket_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.__socket_server.connect((self.__ip_address, self.__port))
        except:
            return False
        self.__fd_socket = self.__socket_server.fileno()
        return True
