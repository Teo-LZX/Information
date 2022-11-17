#include<iostream>
using namespace std;

class clock
{
public:
    int h, m, sec;
    clock() {}
    void setTime(int a, int b, int c) 
    {
        h=a;m=b;sec=c;
    }
    void showTime() 
    {
        if(h<0 || h>23 || m<0 || m>59 || sec<0 || sec>59)
            cout << "illegal time" << endl;
        else 
            cout << h << " " << m << " " << sec << endl;
    }
};
int main()
{
    clock p;
    int a,b,c;
    cin >> a >> b >> c;
    p.setTime(a, b, c);
    p.showTime();
}