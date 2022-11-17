import sys
from tkinter import font
sys.path.append('/home/mercury/文档/Code/python/product2/')
sys.path.append('/home/mercury/文档/Code/python/product2/func')
sys.path.append('/usr/lib/python3.10/qt_material/')
sys.path.append('/usr/lib/python3.10/')
from PyQt5 import QtCore, QtWidgets, QtGui
from MainWindow1 import MainWindow
from login_page import Login
from chat_page import Chat
from qt_material import apply_stylesheet

class QSSLoader:
    def __init__(self):
        pass
    @staticmethod
    def read_qss_file(qss_file_name):
        with open(qss_file_name, 'r',  encoding='UTF-8') as file:
            return file.read()


if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    main_window = MainWindow()
    chat_page = Chat(main_window)
    login_page = Login(main_window, chat_page)
    apply_stylesheet(app, theme='light_teal_500.xml')
    # login_page.show()
    chat_page.show()
    sys.exit(app.exec_())
    os._exit()