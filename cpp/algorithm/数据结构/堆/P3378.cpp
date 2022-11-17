#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr;
    vector<int> res;
    int n;
    cin >> n;
    make_heap(arr.begin(), arr.end(), greater<int>());
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(x == 1){
            int y; cin >> y;
            arr.push_back(y);
            push_heap(arr.begin(), arr.end(), greater<int>());
        }
        else if(x == 2)
            cout << arr.front() << endl;
        else if(x == 3){
            pop_heap(arr.begin(), arr.end(), greater<int>());
            arr.pop_back();
        }
    }
    
}