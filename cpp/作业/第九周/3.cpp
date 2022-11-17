#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

class BaseClass
{
public:
    void fn1() { cout << "BaseClass:fn1()" << endl; }
    void fn2() { cout << "BaseClass:fn2()" << endl; }
};
class DerivedClass: public BaseClass
{
public:
    void fn1() { cout << "DerivedClass:fn1()" << endl; }
    void fn2() { cout << "DerivedClass:fn2()" << endl; }
};
int main()
{
    DerivedClass dc;
    BaseClass *pb = &dc;
    DerivedClass *pd = &dc;
    dc.fn1();
    dc.fn2();
    pb->fn1();
    pb->fn2();
    pd->fn1();
    pd->fn2();
}

