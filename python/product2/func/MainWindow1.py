import sys
import os
import time
from time import sleep
import json, socket
from soupsieve import select
sys.path.append('/home/mercury/文档/Code/python/product2/')
sys.path.append('/home/mercury/文档/Code/python/product2/venv')
from PyQt5 import QtCore, QtWidgets, QtGui
from PyQt5.QtWidgets import QMainWindow
from Ui_MainWindow1 import Ui_MainWindow

class MainWindow(Ui_MainWindow, QtWidgets.QMainWindow):
    def __init__(self) -> None:
        super().__init__(parent=None)
        self.setupUi(self)
        self.show()
        
            
# user_info = json.dumps({"name":'bob', "password":'123'})
# url = 'http://mercury.natapp1.cc/login'
# headers = {'Content-Type': 'application/json'}
# r = requests.post(url=url, verify=False, headers=headers, data=user_info)
# print(r.json()['status'])

# server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# host = '87ed206748692137.natapp.cc'
# port = 1234
# server.connect((host, port))
# server.send('hello world'.encode('utf-8'))
# print(server.recv(4096).decode())