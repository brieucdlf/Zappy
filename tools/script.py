import os
import threading

def execute_client():
    os.system("python ../src_client/client_infinity/main.py")

for i in range(1, 250):
    t = threading.Thread(target=execute_client)
    t.start()
