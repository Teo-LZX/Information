#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<stdlib.h>
using namespace std;

class Rectangle{
    private:
        pair<double, double> A, B;
    public:
        Rectangle();
        void showArea();
};
Rectangle:: Rectangle(){
    cout << "Input Point A:";
    cin >> A.first >> A.second;
    cout << "Input Point B:";
    cin >> B.first >> B.second;
}
void Rectangle:: showArea(){
    double length = B.first - A.first;
    double width = B.second - A.second;
    cout << "Rectangle Area:" << length*width;
}

int main()
{
    Rectangle R;
    R.showArea();
}