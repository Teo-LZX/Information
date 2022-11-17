#include<iostream>
#include<string>
using namespace std;

class Account
{
public:
    Account(string name, string id, float b):name(name), id(id), balance(b) {}
    void deposit(float s)
    {
        balance += s;
    }
    void withdraw(float s)
    {
        if(balance>=s)
        {
            balance -= s;
            cout << "取款成功" << endl;
        }    
        else
        {
            cout << "余额不足" << endl;
        }
    }
private:
    string name, id;
    float balance;
};

int main()
{
    Account a("bob", "123", 1000);
    a.deposit(1000);
    a.deposit(2000);
    a.withdraw(4000);
    a.withdraw(1);
}