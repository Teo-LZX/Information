#include<iostream>
using namespace std;
template<class T>
void show(T a[], int n)
{
    for(int i=0;i<n;++i)
        cout << a[i] << " ";
}
template<class T>
void insertionSort(T a[], int n)
{
    int i,j;
    int temp;
    for(int i=1;i<n;++i)
    {
        int j=i;
        T temp = a[i];
        while(j>0 && temp<a[j-1])
        {
            a[j] = a[j-1];
            --j;
        }
        a[j] = temp;
        show(a, n);
        cout << endl;
    }
}
int main()
{
    int data[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
    insertionSort(data, 20);
}