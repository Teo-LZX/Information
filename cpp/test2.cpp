// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;

// class CCircle
// {
// public:
//     CCircle(float r):radius(r) {}
//     float getPerim()
//     {
//         return 2*3.14*radius;   
//     }
//     float getArea()
//     {
//         return 3.14*radius*radius;
//     }
//     CCircle operator+(const CCircle& c)
//     {
//         return CCircle(radius+c.radius);
//     }
// private:
//     float radius;
// };
// int main()
// {
//     CCircle a(50), b(50);
//     CCircle c = a+b;
//     cout << c.getArea() << " " << c.getPerim() << endl;
// }

#include <iostream>
#include <complex>
using namespace std;
class Base
{
public:
    Base() {cout<<"Base-ctor"<<endl;}
    ~Base() {cout<<"Base-dtor"<<endl;}
    virtual void f(int){cout<<"Base::f(int)"<<endl;}
    virtual void f(double){cout<<"Base::f(double)"<<endl;}
    virtual void g(int i=10){cout<<"Base::g()"<<i<<endl;}
};

class Derived : public Base
{
public:
    Derived() {cout<<"Derived-ctor" <<endl;}
    ~Derived(){cout<<"Derived-dtor"<<endl;}
    void f(complex<double>) {
        cout<<"Derived::f(complex)"<<endl;
    }
    void g(int   i=20){
        cout<<"Derived::g()"<<i<<endl;
    }
};
int main()
{
    cout<<sizeof(Base)<<endl;
    cout<<sizeof(Derived)<<endl;
    Base b;
    Derived d;
    Base *pb=new Derived;
    b.f(1.0);
    d.f(1.0);
    pb->f(1.0);
    b.g();
    d.g();
    pb->g();
    delete pb;
    return 0;
}