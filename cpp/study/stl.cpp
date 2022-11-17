// #include<iostream>
// using namespace std;

// class Base
// {
// public:
//     int x;
//     Base() { cout << "Base constructor\n"; }
//     void print() { cout << "hello\n"; }
// };
// class Derived : public Base
// {};
// int main()
// {
//     Derived *d = new Derived;
//     d->x = 999;
//     void* p = d;
//     Base* b = static_cast<Base*>(p);
//     b->print();
//     cout << b->x << endl;
// }


#include <iostream>
using namespace std;

struct Base1 {int x;};
struct Base2 {float y;};
struct Derived : Base2,Base1{};

int main()
{
    Derived *pd=new Derived;         //派生类指针
    pd->x=1;pd->y=2.0f;              
    void *pv = pd;       
    Base2 *pb=static_cast<Base2*>(pv);   //派生类指针赋值给基类指针
    cout<<pd->y<<" "<<pb->y<<endl;
    delete pd;
    return 0;
}
