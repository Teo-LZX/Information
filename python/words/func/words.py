import sys, functools, socket, threading, time
sys.path.append('/home/mercury/文档/Code/python/words/')
sys.path.append('/home/mercury/文档/Code/python/words/venv')
sys.path.append('/home/mercury/文档/Code/python/words/func')
sys.path.append('/usr/lib/python3.10/qt_material/')
sys.path.append('/usr/lib/python3.10/')
from PyQt5 import QtCore, QtWidgets, QtGui
from PyQt5.QtGui import QPixmap, QImage, QIcon, QFont
from PyQt5.Qt import QThread
from PyQt5.QtWidgets import QMessageBox, QListView, QStatusBar, QMenuBar, QMenu, QAction, QLineEdit,QStyle, QTextBrowser
from PyQt5.QtWidgets import QFormLayout, QVBoxLayout,QWidget,QApplication ,QHBoxLayout, QPushButton,QMainWindow,QGridLayout,QLabel
from PyQt5.QtCore import QStringListModel,QAbstractListModel,QModelIndex,QSize, QThread
from Ui_words import Ui_Form

standard_answer = ''
user_answer_correct = 0
lock = threading.Lock()
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_ip = '16c6ff277c192951.natapp.cc'
server_port = 6060

sno = ''  #当前用户学号
name = ""  #当前用户姓名
tasks = 100

members = []

class Student():
    def __init__(self, sno=0, name='0', depart='0', spsd='0'):
        self.sno = sno
        self.name = name
        self.depart = depart

class Thread(QThread):
    def __init__(self, data, ui, server):
        super(Thread, self).__init__()
        self.data = data
        self.ui = ui
        self.server = server
    # def run(self):
    #     global standard_answer
    #     for w in self.data:
    #         standard_answer = w[2]
    #         user_answer_correct = 0
    #         self.ui.set_button_enabled()
    #         self.ui.label_word.setText("<h> w[0] </h>")
    #         v = w[1]
    #         self.ui.pushButton_A.setText(v[0])
    #         self.ui.pushButton_B.setText(v[1])
    #         self.ui.pushButton_C.setText(v[2])
    #         self.ui.pushButton_D.setText(v[3])
    #         for i in range(3):
    #             self.ui.label_word.setText(w[0] + '              time:' + str(3-i))
    #             time.sleep(1)
    #         if user_answer_correct == 1:
    #             self.ui.label_word.setText(w[0] + '              回答正确')
    #             self.ui.server.send('1'.encode('utf-8'))
    #             #time.sleep(1)
    #         else:
    #             self.ui.label_word.setText(w[0] + '              回答错误')
    #             #time.sleep(1)
            
    #     self.ui.label_word.setText("Game over")
    #     self.ui.pushButton_A.setText(' ')
    #     self.ui.pushButton_B.setText(' ')
    #     self.ui.pushButton_C.setText(' ')
    #     self.ui.pushButton_D.setText(' ')
    #     self.ui.set_button_disenabled()

class Words(Ui_Form, QtWidgets.QWidget):
    def connect_to_server(self):
        host = '87ed206748692137.natapp.cc'
        port = 1234
        self.server.connect((host, port))
    
    # def is_one_clicked(self):
    #     if self.pushButton_A.isChecked() or self.pushButton_B.isChecked() or self.pushButton_C.isChecked() or self.pushButton_D.isChecked():
    #         return True
    #     return False

    def __init__(self) -> None:
        super().__init__(parent=None)
        self.setupUi(self)

    def closeEvent(self, event):
        reply = QtWidgets.QMessageBox.question(self,
                                               '本程序',
                                               "是否要退出程序？",
                                               QtWidgets.QMessageBox.Yes | QtWidgets.QMessageBox.No,
                                               QtWidgets.QMessageBox.No)
        if reply == QtWidgets.QMessageBox.Yes:
            event.accept()
            self.s.sendto('#exit'.encode('utf-8'), (server_ip, server_port))
        else:
            event.ignore()
   
# class Game(Words):
#     def __init__(self) -> None:
#         super().__init__()
#         self.pushButton_A.clicked.connect(functools.partial(self.on_click_A))
#         self.pushButton_B.clicked.connect(functools.partial(self.on_click_B))
#         self.pushButton_C.clicked.connect(functools.partial(self.on_click_C))
#         self.pushButton_D.clicked.connect(functools.partial(self.on_click_D))
#         self.pushButton_begin.clicked.connect(self.begin_PK)

#     def begin_game(self, data):
#         global standard_answer
#         for w in data:
#             standard_answer = w[2]
#             user_answer_correct = 0
#             self.set_button_enabled()
#             self.label_word.setText("<h> w[0] </h>")
#             v = w[1]
#             self.pushButton_A.setText(v[0])
#             self.pushButton_B.setText(v[1])
#             self.pushButton_C.setText(v[2])
#             self.pushButton_D.setText(v[3])
#             for i in range(3):
#                 self.label_word.setText(w[0] + '              time:' + str(3-i))
#                 time.sleep(1)
#             if user_answer_correct == 1:
#                 self.label_word.setText(w[0] + '\n回答正确')
#                 self.server.send('1'.encode('utf-8'))
#                 time.sleep(1)
#             else:
#                 self.label_word.setText(w[0] + '\n回答错误' + '\n正确答案:' + standard_answer)
#                 self.server.send('0'.encode('utf-8'))
#                 time.sleep(1)
            
#         self.label_word.setText("Game over")
#         self.pushButton_A.setText(' ')
#         self.pushButton_B.setText(' ')
#         self.pushButton_C.setText(' ')
#         self.pushButton_D.setText(' ')
#         self.set_button_disenabled()
#         self.server.send('exit'.encode('utf-8'))
    
#     def begin_PK(self):
#         self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#         self.connect_to_server()
#         time.sleep(1)
#         self.server.send('ready'.encode('utf-8'))
#         data = self.server.recv(1024).decode() #接收单词
#         data2 = eval(data)
#         th = threading.Thread(target=self.begin_game, args=(data2,))
#         th.setDaemon(True)
#         th.start()

#     def set_button_disenabled(self):
#         self.pushButton_A.setDisabled(True)
#         self.pushButton_B.setDisabled(True)
#         self.pushButton_C.setDisabled(True)
#         self.pushButton_D.setDisabled(True)
        
#     def set_button_enabled(self):
#         self.pushButton_A.setEnabled(True)
#         self.pushButton_B.setEnabled(True)
#         self.pushButton_C.setEnabled(True)
#         self.pushButton_D.setEnabled(True)

#     def on_click_A(self):
#         lock.acquire()
#         if standard_answer == 'A':
#             user_answer_correct = 1
#         lock.release()
#         self.set_button_disenabled()

#     def on_click_B(self):
#         lock.acquire()
#         if standard_answer == 'B':
#             user_answer_correct = 1
#         lock.release()
#         self.set_button_disenabled()
        
#     def on_click_C(self):
#         lock.acquire()
#         if standard_answer == 'C':
#             user_answer_correct = 1
#         lock.release()
#         self.set_button_disenabled()
        
#     def on_click_D(self):
#         lock.acquire()
#         if standard_answer == 'D':
#             user_answer_correct = 1
#         lock.release()
#         self.set_button_disenabled()
        
class Group(Words):
    def __init__(self) -> None:
        super().__init__()
        self.setMinimumWidth(600)
        self.setMinimumHeight(400)
        self.s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.s.bind(('', 7788))
        #self.s.sendto('#connect'.encode('utf-8'), (server_ip, server_port))
        self.pushButton_send.clicked.connect(self.send_message)
        self.pushButton.clicked.connect(self.query)
        self.textBrowser_lists = []
        self.current_member_item = ''
        self.init_groups()
        self.textBrowser_message = self.textBrowser

        th = threading.Thread(target=self.recv_message)
        th.setDaemon(True)
        th.start()
    
    def mousePressEvent(self, a0: QtGui.QMouseEvent) -> None:
        if a0.buttons () == QtCore.Qt.LeftButton:
            self.word()
            th = threading.Thread(target=self.get_info)
            th.setDaemon(True)
            th.start()
        return super().mousePressEvent(a0)

    def init_groups(self):
        self.s.sendto('#group_member'.encode('utf-8'), (server_ip, server_port))
        qlist = []
        g_id = ''
        while True:
            data = self.s.recv(1024)
            print(data.decode())
            if data == b'#end':
                break
            ss = eval(data.decode('utf-8'))
            qlist.append(ss[1])
            members.append(ss)

        self.listWidget_friends.addItems(qlist)
        self.pushButton_2.clicked.connect(self.renshi)
        self.pushButton_3.clicked.connect(self.mohu)
        self.pushButton_4.clicked.connect(self.burenshi)

        self.textBrowser.show()
       
    def send_message(self):
        data_local = '<span><font size="3">' + self.stu.name + ': ' + self.textEdit_input.toPlainText() + '</font></span>'
        data_send = self.stu.name + '@' + self.textEdit_input.toPlainText()
        self.s.sendto(data_send.encode('utf-8'), (server_ip, server_port))
        self.textEdit_input.clear()
        self.textBrowser.append(data_local)
        
    def recv_message(self):
        while True:
            data_recv = self.s.recv(1024).decode('utf-8').split('@')
            if len(data_recv)>1:
                data_display = data_recv[0] + ':' + data_recv[1]
            try:
                if data_display!=b'':
                    print('h')
                    #self.textBrowser.append(data_display)
            except:
                print("show receive message error!")
    
    def renshi(self):
        global tasks
        try:
            self.label.setText(self.wordss[self.cur_word][1])
            tasks = tasks-1
        except:
            print("getting word error!")
        self.cur_word = (self.cur_word + 1)%len(self.wordss)

    def mohu(self):
        try:
            self.label.setText(self.wordss[self.cur_word][1])
        except:
             print("getting word error!")
        self.cur_word = (self.cur_word + 1)%len(self.wordss)

    def burenshi(self):
        try:
            self.label.setText(self.wordss[self.cur_word][1])
        except:
             print("getting word error!")
        self.cur_word = (self.cur_word + 1)%len(self.wordss)
    
    def word(self):
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.connect(('87ed206748692137.natapp.cc', 1234))
        data = server.recv(1024).decode('utf-8')
        self.wordss = eval(data)
        self.label.setFont(QFont("Roman times", 40, QFont.Bold))
        self.label.setText(self.wordss[0][1])
        self.cur_word = 1
        
    def get_info(self):
        s.sendto('#stu_info'.encode('utf-8'), (server_ip, server_port))
        stu_info = s.recv(1024).decode('utf-8').split('#')
        while True:
            time.sleep(2)
            try:
                self.stu = Student(stu_info[0], stu_info[1], stu_info[2])
                stu = self.stu
                self.label_myname.setFont(QFont("Roman times", 30, QFont.Bold))
                self.label_myid.setFont(QFont("Roman times", 30, QFont.Bold))
                self.label_mydepart.setFont(QFont("Roman times", 30, QFont.Bold))
                self.label_mytask.setFont(QFont("Roman times", 30, QFont.Bold))
                self.label_myname.setText('姓名：' + stu.name)
                self.label_myid.setText('学号：' + str(stu.sno))
                self.label_mydepart.setText('学院：' + stu.depart)
                self.label_mytask.setText('剩余任务：' + str(tasks))
                name = stu.name
                sno = stu.sno
            except:
                print("get student info error!")
    
    def query(self):           #查单词模块
        try:
            s.sendto('#query'.encode('utf-8'), (server_ip, server_port))
            word = self.lineEdit.text()
            s.sendto(word.encode('utf-8'), (server_ip, server_port))
            data = s.recv(1024).decode('utf-8')
            info = eval(data)
            if len(info)!=0:
                self.textBrowser_word.setFont(QFont("Roman times", 30, QFont.Bold))
                self.textBrowser_word.setText(info[0] + ' ' + info[1])
            else:
                self.textBrowser_word.setFont(QFont("Roman times", 30, QFont.Bold))
                self.textBrowser_word.setText('没有该单词')
        except:
            print("query word error!")

class MyInfo(Words):
    def __init__(self) -> None:
        super().__init__()
        # stu_info = s.recv(1024).decode('utf-8').split('#')
        # stu = Student(stu_info[0], stu_info[1], stu_info[2], stu_info[3])
        # self.label_myname.setText(stu.name)
        # self.label_myid.setText(str(stu.sno))
        # self.label_mydepart.setText(stu.depart)
        # self.label_mytask.setText('100')

class Start(Group, MyInfo):
    def __init__(self) -> None:
        super().__init__()
        
