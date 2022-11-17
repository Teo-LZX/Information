#include<iostream>
using namespace std;

class Employee
{
public:
    virtual void speak() { cout << "普通员工" << endl; }
};
class Manager:public Employee
{
public:
    void speak() { cout << "经理 " << endl; }
};

int main()
{
    Employee *p, employee;
    Manager manager;
    p = &employee;
    p->speak();
    p = &manager;
    p->speak();
}