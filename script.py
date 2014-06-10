import os
import threading

def execute_client():
    os.system("./client")

for i in range(1, 100):
    t = threading.Thread(target=execute_client)
    t.start()
