#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Distance{
    private:
        int feet;
        int inches;
    public:
        Distance(){
            feet=0;
            inches=0;
        }
        Distance(int f, int i){
            feet=f, inches=i;
        }
        void DisplayDistance(){
            cout << "F:" << feet  << "  " << "I:" <<inches << endl;
        }
        void operator -(){
            feet = -feet;
            inches = -inches;
            //return Distance(feet, inches);
        }
};

class Time{
    private:
        int hours;
        int minutes;
    public:
        Time():hours(0), minutes(0){}
        Time(int h, int m):hours(h), minutes(m){}
        void Display(){
            cout <<"H:" << hours <<"M:" << minutes << endl;
        }
};

int main()
{
    Distance D1(10, 9), D2(5, 6);
    -D1; 
    -D2;
    D1.DisplayDistance();
    D2.DisplayDistance();
}