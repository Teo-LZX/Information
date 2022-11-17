from gettext import bind_textdomain_codeset
import socket

s = socket.socket()
# host = '87ed206748692137.natapp.cc'
host = '127.0.0.1'
port = 12345
s.bind((host, port))
s.listen(20)
sockets = []
conn, client_addr = s.accept()
print("client--", client_addr, "connected")

while 1:
    msg = conn.recv(1024)
    print(msg.decode())
    conn.send(('hello world').encode())
s.close()
conn.close()