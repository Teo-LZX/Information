#include<iostream>
#include "vector.h"
using namespace std;

vector<int> arr;
int parent(int x)
{
    return x/2;
}
int right(int x)
{
    return x*2+1;
}
int left(int x)
{
    return x*2;
}
void swap(int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[i+1];
    arr[i+1] = tmp;
}
int main()
{
    
    int n; cin >> n;
    for(int i=0;i<n;i++)
    {
        int op;cin >> op;
        if(op == 1)
        {
            int x; cin >> x;
        }
        else if(op == 2)
        {
            
        }
        else if(op == 3)
        {

        }
    }
}