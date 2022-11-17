import socket

server_ip = '127.0.0.1'
server_port = 9999

class Client():
    def __init__(self, client_ip, client_port):
        self.client_ip = client_ip
        self.client_port = client_port
    

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # socket.SOCK_DGRAM代表是UDP通信
s.bind(('', 12345))
s.sendto('connect'.encode('utf-8'), (server_ip, server_port))
while True:
    # data = input().encode('utf-8')
    # 发送数据
    # s.sendto(data, (server_ip, server_port))
    # 接收数据
    print('recv:', s.recv(1024).decode('utf-8'))
    # if data == 'exit':
    #     break
s.close()
