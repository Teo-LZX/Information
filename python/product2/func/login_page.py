import sys, json, requests, functools
from django.forms import PasswordInput
from Ui_login_page import Ui_Form
from PyQt5 import QtCore, QtWidgets, QtGui


class Login(Ui_Form, QtWidgets.QWidget):
    def __init__(self, main_window, chat_page) -> None:
        super().__init__(parent=None)
        self.setupUi(self)
        self.pushButton_login.clicked.connect(functools.partial(self.login, main_window, chat_page))
        self.label_login_clue.hide()
        self.label.hide()
        main_window.hide()
    def login(self, main_window, chat_page):
        name=self.lineEdit_user.text()
        psd=self.lineEdit_psd.text()
        user_info = json.dumps({"name":name, "password":psd})
        url = 'http://mercury.natapp1.cc/login'
        headers = {'Content-Type': 'application/json'}
        r = requests.post(url=url, verify=False, headers=headers, data=user_info)
        if r.json()['status'] == True:
            self.label.setText("登录成功")
            self.label.show()
            self.label_login_clue.hide()
            self.show()
            # main_window.show()
            self.hide()
            chat_page.show()
            # self.widget_login.hide()
        else:
            self.label_login_clue.show()
            self.label_login_clue.setText('用户名或密码错误')
            self.label.hide()