#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int res=0;
    vector<int> arr;
    cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    make_heap(arr.begin(), arr.end(), greater<int>());
    while(arr.size() > 1){
        int a, b;
        a = arr.front(); 
        pop_heap(arr.begin(), arr.end(), greater<int>());
        arr.pop_back();
        b = arr.front();
        pop_heap(arr.begin(), arr.end(), greater<int>());
        arr.pop_back();
        arr.push_back(a+b);
        push_heap(arr.begin(), arr.end(), greater<int>());
        res += a+b;
    }
    cout << res;
}