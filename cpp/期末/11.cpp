#include<iostream>
using namespace std;

class R
{
public:
    R(int r1, int r2):r1(r1), r2(r2) { cout << "构造R" << endl; }
    void print() const { cout << r1 << "-" << r2 << endl; }
    void print() { cout << r1 << "+" << r2 << endl; }
private:
    int r1, r2;
};

int main()
{
    R a(10,20);
    const R b(30,40);
    a.print();
    b.print();       //常量对象只能调用常函数
}