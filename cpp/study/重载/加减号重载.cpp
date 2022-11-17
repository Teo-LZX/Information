#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Number{
    private:
        double real;
        double img;
    public:
        Number():real(0), img(0){}
        Number(int r, int i):real(r), img(i){}
        double get_real() {return real;}
        double get_img() {return img;}
        void show(){
            cout << "real: " << real << " img:" << img << endl;
        }
        // Number operator+(Number &p){    //成员函数重载+号
        //     Number temp;
        //     temp.real = real + p.real;
        //     temp.img = img + p.img;
        //     return temp;
        // }
};
Number operator+(Number &a, Number &b){   //全局函数重载+号
    return Number(a.get_real() +b.get_real(), a.get_img() + b.get_img());
}
int main()
{
    Number a(2, -3), b(-1, 4);
    Number c = a + b;
    a.show(); b.show();
    c.show();
}