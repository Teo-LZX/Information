#include<iostream>
using namespace std;

class Base
{
private:
    int x;
public:
    Base() {
        cout << "Base constructor with no args called" << endl;
    }
    Base(int x):x(x) {
        cout << "Base constructor with one agrs called x=" << x << endl;
    }
    // Base(Base& b)              //要自己定义复制构造函数
    // {
    //     b.x = x;
    //     cout << "Base copy constructor called" << endl;
    // }
    virtual void fun1()   //虚函数
    {
        cout << "Base_fun1 x =  " << x << endl;
    }
    void fun2()
    {
        cout << "Base_fun2 x = " << x << endl;
    }
    int get_x() { return x; }
};
class A:public Base
{
private:
    int x;
public:
    A(int x):x(x) {}
    void fun1()
    {
        cout << "A_fun1 x = " << x << endl;
    }
    void fun2()
    {
        cout << "A_fun2   x = " << x << endl;
    }
};
void show(Base* p)   //基类指针
{
    p->fun2();     //通过基类指针只能调用基类的fun2函数
    p->fun1();    //fun1是虚函数，p指向哪个对象，就调用相应的fun1
}
int main()
{
    Base a(99);   
    cout << a.get_x() << endl;
    A b(20);       //派生类会自动调用基类的无参构造函数
    //a = b;       //类型转换，用派生类对象给基类对象赋值
    show(&a);
    show(&b);  
    
}