import sys
import os
sys.path.append('/home/mercury/文档/Code/python/product/')
sys.path.append('/home/mercury/文档/Code/python/product/venv')
from venv.login import Ui_DockWidget
from PyQt5 import QtCore, QtGui, QtWidgets

class login(Ui_DockWidget, QtWidgets.QDockWidget):
    def __init__(self, parent=None):
        super(Ui_DockWidget, self).__init__(parent)
        self.setupUi(self)
        self.pushButton.clicked.connect(self.on_click)
    def on_click(self):
        name = self.user_Edit.displayText()
        psd = self.psd_Edit.displayText()
        self.name.setText(name)
        self.psd.setText(psd)

    
