from email import message
import sys, json, requests, functools, socket, threading, os, time
from turtle import end_fill
from PyQt5 import QtCore, QtWidgets, QtGui
from PyQt5.QtGui import QPixmap, QImage
from PyQt5.Qt import QThread
from PyQt5.QtWidgets import QMessageBox, QListView, QStatusBar, QMenuBar, QMenu, QAction, QLineEdit,QStyle
from PyQt5.QtWidgets import QFormLayout, QVBoxLayout,QWidget,QApplication ,QHBoxLayout, QPushButton,QMainWindow,QGridLayout,QLabel
from PyQt5.QtCore import QStringListModel,QAbstractListModel,QModelIndex,QSize
from Ui_chat_page import Ui_Form

class Chat(Ui_Form, QtWidgets.QWidget):
    def init_css(self):
        self.setupUi(self)
        self.textEdit_msg.setFontPointSize(15)
        self.textEdit_msg.setFontFamily('SimHei')
        self.textBrowser_show_msg.setFontPointSize(15)
        self.textBrowser_show_msg.setFontFamily('SimHei')
        
        #self.listView_friends.setModel(item)
    def init_bind(self, server):
        self.pushButton_send_msg.clicked.connect(functools.partial(self.send_msg, server))
        self.pushButton_clear.clicked.connect(self.clear_msg)
        host = '87ed206748692137.natapp.cc'
        port = 1234
        server.connect((host, port))
        server.sendall(("Mercury").encode('utf-8'))
    def __init__(self, main_window) -> None:
        super().__init__(parent=None)
        self.init_css()
        exit_flag = False
        # socket
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        #self.init_bind(server)

        # th = threading.Thread(target=self.recv_msg, args=(server, ))
        # th.setDaemon(True)
        # th.start()
        # friends
        items = ["Mercury", "Tom"]
        self.listWidget_friends.addItems(items)
        self.acceptDrops = True
        self.setAcceptDrops(True)
        self.textEdit_msg.setAcceptDrops(True)
    
    def recv_msg(self, server):
        while True:
            data = server.recv(1024)
            print ('%s: received "%s"' % (server.getsockname(), data))
            self.textBrowser_show_msg.append(data.decode())
        
    def send_msg(self, server):
        msg = self.textEdit_msg.toPlainText()
        if len(msg)>0 and (msg[0] == "f" or msg[0] == 'F'):
            self.send_file(msg[1:], server)
        else:
            self.textBrowser_show_msg.setFontPointSize(14)
            self.textBrowser_show_msg.append(self.lineEdit_name.text())
            cursor = self.textBrowser_show_msg.textCursor()
            
            cursor.setPosition(cursor.position() - len(msg))
            self.textBrowser_show_msg.setFontPointSize(15)
            self.textBrowser_show_msg.append(msg)
            self.textEdit_msg.clear()
            print('%s: sending "%s"' % (server.getsockname(), msg))
            server.sendall(("Mercury_@:" + msg).encode('utf-8'))
    
    def clear_msg(self):
        self.textBrowser_show_msg.clear()
        self.textEdit_msg.clear()
    
    def send_file(self, file_name, server):
        if os.path.isfile(file_name):
            size = os.stat(file_name).st_size
            server.sendall(str(size).encode('utf-8'))
        else:
            print("文件路径错误", file_name)
    
    def dragEnterEvent(self,e):
        print(e)
        if e.mimeData().hasText():
            e.accept()
        else:
            e.ignore()
    

