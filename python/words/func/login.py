import sys, socket
sys.path.append('/home/mercury/文档/Code/python/words/')
sys.path.append('/home/mercury/文档/Code/python/words/venv')
sys.path.append('/home/mercury/文档/Code/python/words/func')
sys.path.append('/usr/lib/python3.10/qt_material/')
sys.path.append('/usr/lib/python3.10/')
from PyQt5 import QtCore, QtWidgets, QtGui
from PyQt5.QtGui import QPixmap, QImage, QIcon
from PyQt5.Qt import QThread
from PyQt5.QtWidgets import QMessageBox, QListView, QStatusBar, QMenuBar, QMenu, QAction, QLineEdit,QStyle, QTextBrowser
from PyQt5.QtWidgets import QFormLayout, QVBoxLayout,QWidget,QApplication ,QHBoxLayout, QPushButton,QMainWindow,QGridLayout,QLabel
from PyQt5.QtCore import QStringListModel,QAbstractListModel,QModelIndex,QSize, QThread
from Ui_login import Ui_Form
from words import Start

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = '16c6ff277c192951.natapp.cc'
port = 6060

class Student():
    def __init__(self, sno=0, name='0', depart='0', spsd='0'):
        self.sno = sno
        self.name = name
        self.depart = depart
        self.spsd = spsd


class Login(Ui_Form, QtWidgets.QWidget):
    def __init__(self) -> None:
        super().__init__()
        self.setupUi(self)
        self.lineEdit_usr.setMinimumSize(180, 30)
        self.lineEdit_psd.setMinimumSize(180, 30)
        self.pushButton_login.setMinimumSize(150, 35)
        self.pushButton_login.clicked.connect(self.login)
    
    def login(self):
        global stu
        usr = self.lineEdit_usr.text()
        psd = self.lineEdit_psd.text()
        info = usr + '#' + psd + '#login'
        s.sendto(info.encode('utf-8'), (host, port))
        while True:
            data = s.recv(1024)
            if data==b'ok':         #登录成功进入主页面
                #self.main.show()
                main = Start()
                main.show()
                self.hide()
                break
            else:
                self.label_inclu.setText('用户名或密码错误')
        
    def closeEvent(self, event):
        reply = QtWidgets.QMessageBox.question(self,
                                               '本程序',
                                               "是否要退出程序？",
                                               QtWidgets.QMessageBox.Yes | QtWidgets.QMessageBox.No,
                                               QtWidgets.QMessageBox.No)
        if reply == QtWidgets.QMessageBox.Yes:
            event.accept()
            self.s.sendto('#exit'.encode('utf-8'), (host, port))
        else:
            event.ignore()
