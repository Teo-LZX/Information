#include<iostream>
using namespace std;

class MyClass1
{
public:
    MyClass1(int i):i(i) { cout << i << ")con.MyClass1" << endl; }
    ~MyClass1() { cout << i << "des.MyClass1" << endl; }
    int i;
};
class MyClass2
{
public:
    MyClass2(int i):i(i) { cout << i << ")con.MyClass2" << endl; }
    ~MyClass2() { cout << i << "des.MyClass2" << endl; }
    int i;
};
class MyTest:public MyClass2, public MyClass1
{
public:
    MyTest():MyClass1(1), MyClass2(2), member1(3), member2(4) {}
private:
    MyClass1 member1;
    MyClass2 member2;
};
int main()
{
    MyTest test;
}