// #include <iostream>
// using namespace std;

// class Base1 
// {
// public:
//     int x;
//     Base1() { cout << "Base1 constructor\n"; }
// };
// class Base2 
// {
// public:
//     float y;
//     Base2() { cout << "Base2 constructor\n"; }
//     void print() { cout << "hello\n"; }
// };

// class Derived : public Base1, public Base2 {};

// int main()
// {
//     Derived *pd=new Derived;         //派生类指针       
//     pd->x=1;pd->y=2;                
//     void *pv = pd;   
//     Base2 *pb= static_cast<Base2*>(pv);   
//     cout << pb->y << endl;    //访问Base2的y     
//     pb->print();         //pb是Base2的指针，访问Base2的print
//     delete pd;
//     return 0;
// }


#include <iostream>
using namespace std;

struct Base1 {int x;};
struct Base2 {float y;};
//struct Derived : Base1,Base2{};    //默认公有继承
struct Derived : Base2,Base1{};   //这种是对的

int main()
{
    Derived *pd=new Derived;
    pd->x=1;pd->y=2.0f;
    void *pv = pd;
    Base2 *pb=static_cast<Base2*>(pv);
    cout<<&pd->y<<" "<<&pb->y<<endl;
    delete pd;
    return 0;
}

