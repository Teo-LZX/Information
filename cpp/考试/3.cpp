#include<iostream>
#include<cmath>
using namespace std;

class Shape
{
public:
    virtual void area()=0;
};
class Triangle:public Shape
{
public:
    float a, b, c;
    Triangle(float a, float b, float c):a(a), b(b), c(c) {}
    void area()
    {
        float p = (a+b+c)/2;
        cout << "三角形面积为:" << sqrt(p*(p-a)*(p-b)*(p-c)) << endl;
    }
};
class Circle:public Shape
{
public:
    float r;
    Circle(float r):r(r) {}
    void area() 
    {
        cout << "圆面积为:" << 3.14*r*r;
    }
};
int main()
{
    Shape* ps;
    float a,b,c,r;
    cin >> a >> b >> c;
    Triangle tt(a,b,c);
    cin >> r;
    Circle cc(r);
    ps = &tt;
    ps->area();
    ps = &cc;
    ps->area();
    return 0;
}