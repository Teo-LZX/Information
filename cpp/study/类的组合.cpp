#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

class Point{
    private:
        int x, y;
    public:
        Point(int xx, int yy);
        ~Point();
        Point(const Point& p);
        void setX(int xx) {x = xx;}
        void setY(int yy) {y = yy;}
        int getX() {return x;}
        int getY() {return y;}
};

Point:: ~Point(){
    cout << "Point 析构函数" << endl;
}
Point:: Point(int xx, int yy): x(xx), y(yy) {
    cout << "Point 普通构造函数" << endl;
}
Point:: Point(const Point& p){
    x = p.x;
    y = p.y;
    cout << "Point 复制构造函数" << endl;
}

class Line{
    private:
        Point p1, p2;
        double len;
    public:
        Line(Point xp1, Point xp2);
        Line(Line &l);
        double getLen() {return len;}
        ~Line();
};

Line:: ~Line(){
    cout << "Line 析构函数" << endl;
}
Line:: Line(Point xp1, Point xp2): p1(xp1), p2(xp2) {
    cout << "Line 普通构造函数" << endl;
    double x = static_cast<double>(p1.getX() - p2.getX());
    double y = static_cast<double>(p1.getX() - p2.getY());
    len = sqrt(x*x + y*y);
}
Line:: Line(Line &l): p1(l.p1), p2(l.p2){
    cout << "Line 复制构造函数" << endl;
}

int main()
{
    Point p1(1, 1), p2(2, 2);
    Line line(p1, p2);
    //Line line2  = line;
    //cout << "The length of line1:" << line.getLen() << endl;
    //cout << "The length of line2:" << line.getLen() << endl;
}