import sys
import os
sys.path.append('/home/mercury/文档/Code/python/product/')
from PyQt5 import QtCore, QtWidgets, QtGui
from function.login import login

if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    main_window = login()
    main_window.show()
    sys.exit(app.exec_())