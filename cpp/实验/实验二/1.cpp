#include<iostream>
#include<math.h>
using namespace std;

class point{
    friend void length();
    private:
        int x,y;
    public:
        static double length;
        void getXY(){
            cout << "Input x,y:";
            cin >> x >> y;
        }
        void show(){
            cout << "(" <<x << "," << y << ")" << endl;
        }
};

double point:: length = 0;
point points[10];
void set(){
    for(int i=0;i<10;i++)
        points[i].getXY();
}
void display(){
    for(int i=0;i<10;i++){
        points[i].show();
    }
}
void length(){
    for(int i=0;i<10;i++){
        int x = points[i].x - points[i-1].x, y = points[i].y - points[i-1].y;
        double l = sqrt(x*x + y*y);
        points[i].length += l;
    }
    cout << "Length:" << points[0].length;
}
int main()
{
    set();
    display();
    length();
}