import socket

s = socket.socket()
server_host = '87ed206748692137.natapp.cc'
server_port = 1234
client_host = '127.0.0.1'
client_port = 4321
s.bind((client_host, client_port))
s.connect((server_host, server_port))

while True:
    _in = input()
    s.send(_in.encode())
    print("from server--", s.recv(1024))

