#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    vector<int> A, B, C;
    int flag=0;
    cin >> a >> b;
    if(a.size() < b.size() || (a.size() == b.size() && a<b)){
        swap(a, b);
        flag=1;
    }
    for(int i=0;i<a.size();i++)
        A.push_back(a[i] - '0');
    for(int i=0;i<b.size();i++)
        B.push_back(b[i] - '0');
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    while(A.size() != B.size()){
        if(A.size() > B.size())
            B.push_back(0);
        else
            A.push_back(0);
    }
    int t=0;
    for(int i=0;i<A.size();i++){
        if(A[i] < B[i]){
            A[i+1]--;
            A[i]+=10;
        }
        C.push_back(A[i] - B[i]);
    }
    int i=C.size()-1;
    while(C[i] == 0 && C.size() > 1){
        i--;
        C.pop_back();
    }
    if(flag==1)
        cout << "-";
    reverse(C.begin(), C.end());
    for(int i=0;i<C.size();i++)
        cout << C[i];
}