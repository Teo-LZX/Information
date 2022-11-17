import sys
sys.path.append('/home/mercury/文档/Code/python/words/')
sys.path.append('/home/mercury/文档/Code/python/words/func')
sys.path.append('/usr/lib/python3.10/qt_material/')
sys.path.append('/usr/lib/python3.10/')
from PyQt5 import QtCore, QtWidgets, QtGui
from words import Start
from login import Login

if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    login = Login()
    login.show()
    sys.exit(app.exec_())