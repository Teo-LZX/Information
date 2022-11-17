#include<iostream>
#include<iomanip>
using namespace std;

int arr[100][100];
int n;

int main()
{
    cin >> n;
    int a = n*n;
    int cur=1;
    int i=0;
    while(cur<a)
    {
        for(int k=i;k<n-1-i ;k++)
            arr[i][k] = cur++;
        for(int k=i;k<n-1-i ;k++)
            arr[k][n-1-i] = cur++;
        for(int k=n-1-i;k>i ;k--)
            arr[n-1-i][k] = cur++;
        for(int k=n-1-i;k>i ;k--)
            arr[k][i] = cur++;
        i++;
    }
    if(n%2==1)
        arr[n/2][n/2] = n*n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << setw(4) << setfill('*') << arr[i][j];
        }
        cout << endl;
    }
}