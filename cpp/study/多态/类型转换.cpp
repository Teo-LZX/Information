#include<iostream>
using namespace std;

class A
{
public:
    //类B中不显示调用类A的构造函数时，系统自动调用
    //A(){cout << "A:constructor with no args" << endl;}
    A(int x): x(x) {cout << "A:constructor with one args" << endl;}
    virtual void fun()
    {
        cout << "obj_A" << endl;
    }
    int get_value() { return x; }
    virtual int get_value2() { return x; } //虚函数
private:
    int x;
};
class B:public A
{
public:
    B(int y): y(y),A(y-1) {cout << "B:construtor with one args" << endl;}
    void fun()
    {
        cout << "obj_B" << endl;
    }
    int get_value() { return y; }
    int get_value2() { return y; }
private:
    int y;
};
void show1(A *p)//类型转换：基类引用指向派生类, 这里的p就只能调用A的方法
{
    p->fun();
    cout << p->get_value() << endl;  //调用A类的方法
    cout << p->get_value2() << endl;  //调用p指向的对象的方法
}
void show2(A &p)//类型转换：基类引用指向派生类, 这里的p就只能调用A的方法
{
    p.fun();
    cout << p.get_value() << endl;  //调用A类的方法
    cout << p.get_value2() << endl;  //调用p指向的对象的方法
}
int main()
{
    A a(100);
    B b(66);
    show1(&b);

}