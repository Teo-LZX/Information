#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void show()
{
    for(auto &ch:arr)
        cout << ch << " ";
    cout << endl;
}

//选择排序
void select_sort()
{
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i)
            swap(arr[i], arr[min]);
    }
}

//冒泡排序
void bubble_sort()
{
    int n= arr.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j+1] < arr[j])
                swap(arr[j+1], arr[j]);
        }
    }
}
//插入排序
void insert_sort()
{
    int n = arr.size();
    for(int i=1;i<n;i++)
    {
        int p = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>p)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = p;
    }
}
//快排
int partition(int l, int r)
{
    int i=l, j=r;
    int x = arr[l];
    while(i<j)
    {
        while(i<j && arr[j]>=x)
            j--;
        while(i<j && arr[i]<=x)
            i++;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    //arr[l] = arr[i];
    //arr[j] = x;
    swap(arr[l], arr[j]);
    return j;
}
void quick_sort(int i, int j)
{
    if(i>j)
        return;
    int s = partition(i, j);
    show();
    quick_sort(i, s-1);
    quick_sort(s+1, j);
}
//二分查找
int flag=0;
int search(int k)
{
    int n = arr.size();
    int l=0, r=n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        flag++;
        cout << arr[mid] << " mid = " << mid << "l=" << l << " r=" << r  << endl;
        if(arr[mid] == k) return mid;
        else if(k > arr[mid]) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int main()
{
    int n; cin >> n;
    arr.resize(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    //select_sort();
    //bubble_sort();
    //insert_sort();
    //int a = search(98);
    //cout << a << "   flag=" << flag << endl;
    quick_sort(0, n-1);
    //show();
}





