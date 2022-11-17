#include<iostream>
using namespace std;

// class A
// {
// public:
//     A() {}
//     virtual void func()
//     { cout << "A::func" << endl; }
//     ~A() {}
//     virtual void fund()
//     { cout << "A::fund" << endl; }
// };
// class B:public A
// {
// public:
//     B() { func(); }
//     void fun() { func(); }
//     ~B() { fund(); }
// };
// class C:public B
// {
// public:
//     C() {}
//     void func()
//     { cout << "C:: func" << endl; }
//     ~C() { fund(); }
//     void fund()
//     { cout << "C:: fund" << endl; }
// };
// ------------------------------------------------------
// class A
// {
// public:
//     virtual ~A() { cout << "D A\n"; }
// };
// class B:public A
// {
// public:
// virtual ~B() { cout << "D B\n"; }
// };
// class C:public B
// {
// public:
//     ~C() { cout << "D C\n"; }
// };

//-----------------------------------------------

// class A
// {
// public:
//     A() {}
//     virtual void func() { cout << "A:: func" << endl; }
//     virtual void fund() { cout << "AA::fund" << endl; }
//     void fun() { cout << "A::fun" << endl; }
// };
// class B:public A
// {
// public:
//     B() { func(); }
//     void fun() { func(); }
// };
// class C:public B
// {
// public:
//     C() {}
//     void func() { cout << "C::func" << endl; }
//     void fund() { cout << "C::fund" << endl; }
// };

//---------------------------------------------------

//  class A
//  {
//     public:
//     void Fun() { cout << "A::Fun" << endl; }
//     void Do() { cout << "A::Do" << endl; }
//  };
//  class B:public A
//  {
//     public:
//     virtual void Do() { cout << "B::Do" << endl; }
//  };
//  class C:public B
//  {
//      public:
//      void Do() { cout << "C::Do" << endl; }
//      void Fun() { cout << "C::Fun" << endl; }
//  };
//  void call(B& p)
//  {
//      p.Fun(); p.Do();
//  }

//--------------------------------------
class A
{
    public:
        void Fun() { cout << "A::Fun\n"; }
        virtual void Do() { cout << "A::Do\n"; }
};
class B:public A
{
    public:
    virtual void Do() { cout << "B::Do\n"; }
};
class C:public B
{
    public:
    void Do() { cout << "C::Do\n"; }
    void Fun() { cout << "C::Fun\n"; }
};
void call(A* p)
{
    p->Fun(); p->Do();
}
int main()
{
    // C c;
    //------------
    // A* pa = new C;
    // delete pa;
    // A a;
    //--------------
    // A* pa = new B();
    // pa->fun();
    // B* pb = new C();
    // pb->fun();
    //-------------------------
    // C c; call(c);
    //--------------------------
    A* a = new A; 
    call(new A);
    C* c = new C;
    call(new C);
    const int* p = 0;
    cout << p;
}