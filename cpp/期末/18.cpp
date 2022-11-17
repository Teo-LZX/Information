#include<iostream>
using namespace std;

class Object
{
public:
    virtual float volume()=0;
};
class Cuboid:public Object
{
public:
    Cuboid(float l, float w, float h):length(l), width(w), high(h) {}
    float volume()
    {
        return length*width*high;
    }
private:
    float length, width, high;
};
class Cylinder:public Object
{
public:
    Cylinder(float r, float h):radius(r), high(h) {}
    float volume()
    {
        return 3.14*radius*radius*high;
    }
private:
    float radius, high;
};
int main()
{
    Cuboid cu(3, 4, 5);
    Cylinder cy(4, 10);
    Object ptr[2] = {&cu, &cy};
    cout << "总体积：" << ptr[0]->volume() << ptr[1]->volume() << endl;
}