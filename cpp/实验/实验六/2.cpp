#include  <iostream>
#include  <cmath>
using  namespace  std;
class  CFraction
{
private:
    int nume;    //  分子
    int deno;    //  分母
public:
    CFraction(int  nu=0,int  de=1):nume(nu),deno(de)  {}
    void  simplify();

    //输入输出的重载
    friend  istream  &operator>>(istream  &in,CFraction  &x);
    friend  ostream  &operator<<(ostream  &out,CFraction  x);

    friend  CFraction  operator+(const  CFraction  &c1,const  CFraction  &c2);    //两个分数相加，结果要化简
    friend  CFraction  operator-(const  CFraction  &c1,const  CFraction  &c2);    //两个分数相减，结果要化简
    friend  CFraction  operator*(const  CFraction  &c1,const  CFraction  &c2);    //两个分数相乘，结果要化简
    friend  CFraction  operator/(const  CFraction  &c1,const  CFraction  &c2);    //两个分数相除，结果要化简
};

CFraction func(int nume, int deno)
{
    int tmp_nume = abs(nume), tmp_deno=abs(deno);
    for(int i=tmp_nume;i>1;--i)
    {
        while(tmp_nume%i==0 && tmp_deno%i==0)
        {
            tmp_nume /= i;
            tmp_deno /= i;
            nume /= i;
            deno /= i;
        }
    }
    return CFraction(nume, deno);
}
istream  &operator>>(istream  &in,CFraction  &x)
{
    char ch;
    cin >> x.nume >> ch >> x.deno;
    return in;
}
ostream  &operator<<(ostream  &out,CFraction x)
{
    if(x.deno!=1) cout << x.nume << "/" << x.deno;
    else cout << x.nume;
    return out;
}
CFraction  operator+(const  CFraction  &c1,const  CFraction  &c2)
{
    int deno = c1.deno*c2.deno;
    int d1 = c1.nume*deno/c1.deno;
    int d2 = c2.nume*deno/c2.deno;
    return func(d1+d2, deno);
}
CFraction  operator-(const  CFraction  &c1,const  CFraction  &c2)
{
    int deno = c1.deno*c2.deno;
    int d1 = c1.nume*deno/c1.deno;
    int d2 = c2.nume*deno/c2.deno;
    return func(d1-d2, deno);
}
CFraction  operator*(const  CFraction  &c1,const  CFraction  &c2)
{
    int nume = c1.deno*c2.deno;
    int deno = c1.nume*c2.nume;
    return func(deno, nume);
}
CFraction  operator/(const  CFraction  &c1,const  CFraction  &c2)
{
    int nume = c1.deno*c2.nume;
    int deno = c1.nume*c2.deno;
    return func(deno, nume);
}
int main()
{
        CFraction  x,y,s;
        cout<<"Input  x:  ";
        cin>>x;
        cout<<"Input  y:  ";
        cin>>y;
        s=x+y;
        cout<<"x+y="<<s<<endl;
        s=x-y;
        cout<<"x-y="<<s<<endl;
        s=x*y;
        cout<<"x*y="<<s<<endl;
        s=x/y;
        cout<<"x/y="<<s<<endl;
        return  0;
}