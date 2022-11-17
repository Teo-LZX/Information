#include  <iostream>
using  namespace  std;

class Point
{
public:
    Point(int a, int b):a(a), b(b) {}
    Point() {}
    Point operator++()
    {
        a++;b++;
        return *this;
    }
    Point operator++(int)
    {
        Point temp(a, b);
        a++; b++;
        return temp;
    }
    Point operator--()
    {
        a--; b--;
        return *this;
    }
    Point operator--(int)
    {
        Point temp(a, b);
        a--; b--;
        return temp;
    }
    void display()
    {
        cout << "(" << a << "," << b << ")" << endl;
    }
private:
    int a,b;
};

int main()
{
    Point  a,b(5,5);
    a=b++;
    a.display();
    a=++b;
    a.display();
    a=--b;
    a.display();
    a=b--;
    a.display();
}