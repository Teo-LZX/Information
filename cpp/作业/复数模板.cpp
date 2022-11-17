#include  <iostream>
#include  <cmath>
using  namespace  std;


class Complex
{
public:
    int real, img;
    Complex() {}
    Complex(int real, int img):real(real), img(img) {}
    void input()
    {
        cin >> real >> img;
    }
    double operator-(const Complex& c)
    {
        return sqrt(pow(img-c.img, 2)+pow(real-c.real, 2)); 
    }
};
template < class T >
double dist(T a, T b)
{
    return abs(a-b);
}

int main()
{
        int  a1,b1;
        double  a2,b2;
        Complex  a3,b3;
        int  type;
        cin>>type;
        if(type==1)
        {
            cin>>a1>>b1;
            cout<<dist(a1,b1)<<endl;
        }
        else if(type==2)
        {
            cin>>a2>>b2;
                cout<<dist(a2,b2)<<endl;
      }
      else
      {
                  a3.input();
                  b3.input();
                  cout<<dist(a3,b3)<<endl;
      }
      return  0;
}