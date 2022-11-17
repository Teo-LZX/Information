#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <thread>
using namespace std;
#define BUFFER_SIZE 1024

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
void func(int& clnt_sock, char* buffer)
{
    while(true)
        {
            //use the new socket to talk with the client
            bool ret = read(clnt_sock, buffer, BUFFER_SIZE); //read data from client
            cout << "sizeof buffer: " << sizeof(buffer);
            if(!ret)
            {
                cout << "Recv error!\n";
                return;
            }
            cout << "Message from client " << clnt_sock << ": " << buffer << endl;
            string str = string(buffer) + to_string(clnt_sock);
            memset(buffer, 0, sizeof(buffer)); 
     
            //send data to client
            char* s = (char*)str.c_str();
            ret = write(clnt_sock, s, strlen(s));
            if(!ret)
            {
                cout << "Send error!\n";
                return;
            }
        }
}

char buffer[100];
int main(){
    //create a socket and socket array
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    vector<int> sockets;

    //bind the socker with ip and port
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    //listen, wait for the client's request
    listen(serv_sock, 20);

    while(true)
    {
        // accept the request, and create a new socket which correponds this request
        struct sockaddr_in clnt_addr;
        socklen_t clnt_addr_size = sizeof(clnt_addr);
        int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        sockets.push_back(clnt_sock);
        cout << "来自" << clnt_sock << "的连接" << endl;
        thread th(func, ref(clnt_sock), ref(buffer));
        th.detach();
        //func(clnt_sock, buffer);
        
    }
    
    //关闭套接字
    //close(clnt_sock);
    //close(serv_sock);

    return 0;
}
