#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

class Brass
{
private:
    string fullName;
    long acctNum;
    double balance;
public:
    Brass(const string & a="NUllbody", long an=-1, double bal=0.01);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};
Brass::Brass(const string& a, long an, double bal):fullName(a), acctNum(an), balance(bal) {}
void Brass::Deposit(double amt)
{
    if(amt < 0)
        cout << "not allowed\n";
    else
        balance += amt;
}
void Brass::Withdraw(double amt)
{
    if(amt < 0)
        cout << "Withdrawal amount must be positive\n";
    else if(amt <= balance)
        balance -= amt;
    else
        cout << "balance 不够\n";
}
double Brass::Balance() const
{
    return balance;
}
void Brass::ViewAcct()const
{
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: " << balance << endl;
}
class BrassPlus:public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const string &s="Nullbody", long an=-1, double bal=0.0, double ml=500, double r=0.11125);
    BrassPlus(const Brass& ba, double ml=500,double r=0.11125);
    virtual void ViewAcct() const;
    virtual void WithDraw(double amt);
    void ResetMax(double m) {maxLoan = m;}
    void ResetRate(double r) {rate = r;}
    void ResetOwes() {owesBank=0;}
};

int main()
{}