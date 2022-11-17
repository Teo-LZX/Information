#include<iostream>
#include "mytime0.h"

int main()
{
    Time planning;
    Time coding(2,40,0);
    Time fixing(5,55,10);
    planning.Show();
    coding.Show();
    fixing.Show();
    Time total = coding.operator+(fixing);
    total = coding + fixing;
    cout << total;
}