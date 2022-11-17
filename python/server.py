import socket

server_ip = '127.0.0.1'
server_port = 9999

class Group():
    def __init__(self, group_name, group_id, group_member):
        self.group_name = group_name
        self.group_id= group_id
        self.group_member = group_member

class User():
    def __init__(self, usr_name, usr_id, usr_psd):
        self.usr_name = usr_name
        self.usr_id = usr_id
        self.usr_psd = usr_psd

class Client():
    def __init__(self, client_ip, client_port):
        self.client_ip = client_ip
        self.client_port = client_port

# 建立套接字
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # socket.SOCK_DGRAM代表是UDP通信
# 绑定IP和端口
s.bind((server_ip, server_port))
print('Bind UDP Server on %s:%s' % (server_ip, server_port))

clients = []
users = [User('bob', '123', '321'), User('tom', '124', '567')]
group = Group('sweet', '999', users)
# a = vars(group.group_member[0])
# print(a)

while True:
    # 接收数据
    data, addr = s.recvfrom(1024)
    if data==b'connect':
        client = Client(addr[0], addr[1])
        clients.append(client)
        print(addr, 'connected')
    
    print(addr, "\t", data)
    # 发送数据
    for c in clients:
        print("sending.....")
        s.sendto(data, (c.client_ip, c.client_port))
    if data == b'exit':
        clients.remove(client)
        break
print(list(clients))