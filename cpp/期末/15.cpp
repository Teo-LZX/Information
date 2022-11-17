#include<iostream>
using namespace std;

int main()
{
    int a[5] = {1,2,3,4,5};
    int i=5;
    try
    {
        if(!(i>=0 && i<5))
            throw i;
    }
    catch(int e)
    {
        cout << "下标越界：" << e << endl;
    }
    
}