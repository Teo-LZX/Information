#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;

bool Send(int& sock, char* buffer, size_t size)
{
    while(size>0)
    {
        int send_size = write(sock, buffer, size);
        if(send_size <= 0)
            return false;
        size -= send_size;
        buffer += send_size;
    }
    return true;
}
bool Recv(int& sock, char* buffer, size_t size)
{
    while(size>0)
    {
        int recv_size = read(sock, buffer, size);
        if(recv_size <= 0)
            return false;
        size -= size;
        buffer += recv_size;
    }
    return true;
}
int main(){
    //create a socket 
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    //bind the client IP and port
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_addr.sin_port = htons(4321);
    int ret = bind(sock, (struct sockaddr*)&client_addr, sizeof(client_addr));
  

    //request to the specific server with IP and port
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    
   
    //读取服务器传回的数据
    char s[100];
    
    while(true)
    {
        cout << "ipnut message:";
        cin.getline(s, 100);
        //cin >> s;
        cout << strlen(s);
        int ret = Send(sock, s, strlen(s));
        if(!ret)
        {
            cout << "Recv error!\n";
            return 0;
        }
        memset(&s, 0, strlen(s));

        char buffer[40];
        memset(buffer, 0, sizeof(buffer));
        ret = Recv(sock, buffer, sizeof(buffer)-1);
        if(!ret)
        {
            cout << "Send error!\n";
            return 0;
        }
        printf("Message from server: %s\n", buffer);
    }
   
    //关闭套接字
    close(sock);

    return 0;
}