#include  <iostream>
using  namespace  std;
class  Employee
{
public:
        Employee(string  id,string  name):id(id),name(name)
        {}
        void  display()
        {
                cout<<"ID:"<<id<<endl;
                cout<<"Name:"<<name<<endl;
        }
protected:
        string  id,name;
};
class Sales:public Employee
{
public:
    Sales(string id, string name, double n):Employee(id, name) 
    {
        salary = 0.1 * n;
    }
protected:
    double salary;
};
class Manager:public Employee
{
public:
    Manager(string id, string name): Employee(id, name)
    {
        salary = 8000;
    }
protected:
    double salary;
};
class SalesManager: public Sales, public Manager
{
public:
    SalesManager(string id, string name, double n): Sales(id, name, n),Manager(id, name)
    {
        this->id = id;  
        this->name = name;
        salary = 5000 + n*5/100;
    }
    void display()
    {
        cout << "ID:" << Sales::id << endl;
        cout << "Name:" << Sales::name << endl;
        cout << "Salary:" << salary << endl;
    }
private:
    string name, id;
    double salary;
};

int  main()
{
        string  id,name;
        float  sale;
        cout<<"Input  id  name  and  sale:"<<endl;
        cin>>id>>name>>sale;
        if(sale<0)
        {
                cout<<"Input  Error!"<<endl;
                return  0;
        }
        SalesManager  sm(id,name,sale);
        sm.display();
        return  0;
}
