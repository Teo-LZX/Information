#include<iostream>
#include<vector>
#include<string>
using namespace std;

//前置递增返回引用，后置递增返回值
class MyInteger{
    friend ostream& operator<<(ostream& out, const MyInteger& p);
    private:
        int myInt;
    public:
        MyInteger(int n): myInt(n) {}
        MyInteger& operator++(){
            myInt++;
            return *this;
        }
        MyInteger operator++(int a){    //返回的是局部对象，不能返回引用，因为局部对象在函数结束后会消亡
            MyInteger temp = *this;
            myInt++;
            return temp;     //返回的是一个临时空间的值  ,引用类型不能引用临时对象或者常量
        }
};
ostream& operator<<(ostream& out,  const MyInteger& p){    //这里不能写成MyInteger &p, 传入的p是一个临时对象，引用类型不能引用临时对象或者常量
    cout << p.myInt;
    return cout;
}
void test(){
    MyInteger myint(99);
    //myint++;
    //cout << myint++ << endl;
    cout << myint++ << endl;
    cout <<++myint <<endl;
}
int main()
{
    //test();
    int i;
    i=0; printf("%d\n", i++ + ++i);
    i=0; printf("%d\n", ++i + ++i);
    i=0; printf("%d\n", i++ + i++);
    i=0; printf("%d\n", ++i + i++);
}
