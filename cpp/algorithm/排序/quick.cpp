#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

void show();
void swap(vector<int>& arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(vector<int>& arr, int low, int high)
{
    int p = arr[low];
    int i=1,j=high;
    do
    {
        do
        {
            i++;
        }while(i<=high && i<j && arr[i]<p);
        do
        {
            j--;
        }while(j>=0 && i<j && arr[j]>p);
        if(i>=j)
            break;
        if(i<j)
            swap(arr, i, j);
    }while(i<j);
    swap(arr, i, j);
    swap(arr, low, j);
    //cout << "partition:" << j << endl;
    return j;
}
void quickSort(vector<int>& arr, int low, int high)
{
    //show();
    if(low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

void show()
{
    for(auto &it:arr)
        cout << it << " ";
    cout << endl;
}
int main()
{
    int n; cin >> n;
    for(int i=0;i<n;i++)
    {
        int x; cin >> x;
        arr.push_back(x);
    }
    show();
    quickSort(arr, 0, arr.size()-1);
    show();
}