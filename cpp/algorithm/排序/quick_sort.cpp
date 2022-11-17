#include<iostream>
#include<vector>
#include<string>
using namespace std;

inline void swap(vector<int> &arr, int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int pariton(vector<int> &arr, int p, int r){
    int i=p, j=r;
    int x  = arr[p];       // 默认以第一个元素为分隔元素
    while(i<j){
        while(i<j && arr[j]>=x)
            j--;
        while(i<j && arr[i]<=x)
            i++;
        if(i < j)
            swap(arr, i, j);
    }
    return j;
}
void quick_sort(vector<int> &arr, int p, int r){
    if(p>=r)
        return;
    int x = arr[(p+r)/2], i=p-1, j=r+1;
    while(i<j){
        do 
        i++;
        while(arr[i]<=x);

        do 
        j--;
        while(arr[j]>=x);
        if(i<j)
            swap(arr, i, j);
    }
   // swap(arr, n, p);
    quick_sort(arr, p, j);
    quick_sort(arr, j+1, r);
}

void show(vector<int> &arr){
    for(auto &it : arr){
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
        cin >> arr[i];
    quick_sort(arr, 0, N-1);
    show(arr);
}