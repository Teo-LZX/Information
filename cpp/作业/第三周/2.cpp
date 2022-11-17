#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Complex{
    private:
        double real, img;
    public:
        Complex(double a, double b);
        Complex(double num);
        void add(Complex& c);
        void show();
};

Complex:: Complex(double a, double b){
    real = a;
    img = b;  
}

Complex:: Complex(double num){
    real = 4.5;
    img = 0;
}
void Complex:: add(Complex &c){
    real += c.real;
    img += c.img;
}
void Complex:: show(){
    cout << real << "+" << img << "i";
}


int main()
{
    Complex c1(3,5);
    Complex c2=4.5;
    c1.add(c2);
    c1.show();
}