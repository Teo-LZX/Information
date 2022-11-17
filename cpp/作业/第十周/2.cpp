#include<iostream>
using namespace std;

class BaseClass
{
public:
    virtual void fn1() {}
    void fn2() { cout << "BaseClass:fn2()\n"; }
};
class DerivedClass:public BaseClass
{
public:
    void fn1() { cout << "DerivedClass:fn1()\n"; }
    void fn2() { cout << "DerivedClass:fn2()\n"; }
};

int main()
{
    DerivedClass dc;
    BaseClass *pb = &dc;
    DerivedClass *pd = &dc;
    pb->fn1();
    pb->fn2();
    pd->fn1();
    pd->fn2();
}