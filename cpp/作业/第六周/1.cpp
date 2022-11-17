#include<iostream>
using namespace std;

class Shape{
    protected:
        int area;
};
class  Rectangle: public Shape{
    private:
        int a, b;
    public:
        Rectangle(){
            cout << "Input a,b:";
            cin >> a >> b;
        }
        double getArea(){
            return a*b;
        }
};
class Square:public Shape{
    private:
        int r;
    public:
        Square(){
            cout << "Input r:";
            cin >> r;
        }
        double getArea(){
            return r*r*3.14;
        }
};
int main()
{
    Rectangle r;
    Square s;
    cout << "Rectangle Area:" << r.getArea() << ",Circle Area:" << s.getArea();

}