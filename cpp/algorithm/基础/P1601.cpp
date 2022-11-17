#include<bits/stdc++.h>
using namespace std;
#define N 1e5

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B, res;
    for(int i=0;i<a.size();i++)
        A.push_back(a[i] - '0');
    for(int i=0;i<b.size();i++)
        B.push_back(b[i] - '0');
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    int t=0;
    int len = max(A.size(), B.size());
    while(A.size() != B.size()){
        if(A.size() < B.size())
            A.push_back(0);
        else
            B.push_back(0);
    }

    for(int i=0;i<len;i++){
        int num = A[i] + B[i] + t;
        if(num >= 10)
            t = 1;
        else
            t = 0;
        res.push_back(num%10);
    
    }
    //cout << "hello world";
    if(t == 1)
        res.push_back(1);
    reverse(res.begin(), res.end());
    for(int i=0;i<res.size();i++)
        cout << res[i];
}