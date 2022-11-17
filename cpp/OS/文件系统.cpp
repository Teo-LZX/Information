#include<iostream>
#include<string>
using namespace std;

class user
{
    string name;//用户名
    string password;//密码
};
class File
{
public:
    string name;
}
class Inode
{
public:
    static const int size = 64;
    string usr_id, group_id;
    long long bytes;   //文件大小
    int links;  //链接数目
};

int main()
{}