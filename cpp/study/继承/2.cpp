#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void fun(int i){
    cout << i << " ";
}
class BaseA{
    public:
        BaseA(int a, int b): a(a), b(b){}
        ~BaseA(){}
    protected:
        int a, b;
};
class BaseB{
    public:
        BaseB(int c, int d): c(c), d(d) {}
        ~BaseB(){}
    protected:
        int c,  d;
};
class Derived: public BaseA, public BaseB{

};
int main()
{
    vector<int> arr{1,2,3,4,5};
    for_each(arr.begin(), arr.end(), fun);
}