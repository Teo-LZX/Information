#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
using namespace std;

class Fen_number
{
public:
    Fen_number(int a, int b)
    {
        son = a; mother = b;
        int tmp_son = abs(son), tmp_mother = abs(mother);
        for(int i=tmp_son;i>1;--i)
        {
            while(tmp_son%i==0 && tmp_mother%i==0)
            {
                tmp_son /= i;
                tmp_mother /= i;
                son /= i;
                mother /=i;
            }
        }
        
    }
    Fen_number operator+(const Fen_number& p)
    {
        int fen_mu = mother*p.mother;
        int fen_zi1 = son*fen_mu/mother;
        int fen_zi2 = p.son*fen_mu/p.mother;
        return Fen_number(fen_zi1+fen_zi2, fen_mu);
    }
    Fen_number operator-(const Fen_number& p)
    {
        int fen_mu = mother*p.mother;
        int fen_zi1 = son*fen_mu/mother;
        int fen_zi2 = p.son*fen_mu/p.mother;
        return Fen_number(fen_zi1-fen_zi2, fen_mu);
    }
    Fen_number operator*(const Fen_number& p)
    {
        int fen_mu = mother*p.mother;
        return Fen_number(son*p.son, fen_mu);
    }
    Fen_number operator/(const Fen_number& p)
    {
        int fen_zi = son*p.mother;
        int fen_mu = mother*p.son;
        return Fen_number(fen_zi, fen_mu);
    }
    void show()
    {
        if(mother!=1)
            cout << son << "/" << mother << endl;
        else
            cout << son << endl;
    }
    int son, mother;
};
int a, b;
int main()
{
    cout << "Input x: ";
    cin >> a; getchar(); cin >> b;
    Fen_number f(a, b);
    cout << "Input y: ";
    cin >> a; getchar(); cin >> b;
    Fen_number f2(a, b);
    Fen_number f3 = f + f2;
    cout << "x+y="; f3.show();
    Fen_number f4 = f-f2;
    cout << "x-y="; f4.show();
    Fen_number f5 = f*f2;
    cout << "x*y="; f5.show();
    Fen_number f6 = f/f2;
    cout << "x/y="; f6.show();
}