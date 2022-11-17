#include<iostream>
#include<cmath>
using namespace std;

const double PI=3.14;
class Base
{
public:
    double r;
    Base() {}
    Base(double r): r(r) {}
};
class cylinder:public Base
{
public:
    cylinder(double height, double r): Base(r), height(height) {}
    void show_area()
    {
        cout << "The area of the cylinder:" << 2*PI*r*height << endl;
    }
    void show_vol()
    {
        cout << "The volume of the cylinder:" << height*PI*r*r << endl;
    }
    double height;
};
class cone:public Base
{
public:
    cone(double height, double r): Base(r), height(height) {}
    void show_area()
    {
        cout << "The area of the cone:" << PI*r*r + 2*PI*r*sqrt(r*r + height*height) << endl;
    }
    void show_vol()
    {
        cout << "The volume of the cone:" << 1.0/3*PI*r*r*height << endl;
    }
    double height;
};

int main()
{
    double r, height;
    cout << "Input the radius of the sphere:";
    cin >> r; 
    cout << "Input the radius and height of the cylinder:";
    cin >> height >> r;
    cylinder c(height, r);
    cout << "Input the radius and height of the cone:";
    cin >> height >> r;
    cone cc(height ,r);
    c.show_area();
    c.show_vol();
    cc.show_area();
    cc.show_vol();
}