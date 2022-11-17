#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

void fun(int n){             //十进制转二进制
    string s;
    while(n){
        int x = n%2;
        char c = x + '0';
        s = c + s;
        n/=2;
    }
    cout << s << endl;
}
void fun2(string s){          //二转十
    long long r=0;
    long long t = 1;
    for(int i=s.size()-1;i>=0;i--){
        r = r + (s[i] - '0') * t;
        t = t*2;
    }
    cout << r << endl;
}
class CMP{
    public:
    bool operator()(const string& a, const string& b)const {
        return a.size() < b.size();
    }
};
int main()
{
    // int n; cin >> n;
    // fun(n);
    // string s; cin >> s;
    // fun2(s);
    string a = "123456";
    reverse(a.begin(), a.end());
    cout << a << endl;
    vector<string> b = {"tom", "bb", "sdfsdaf", "fsdf", "dsfad", "dfwerr"};
    sort(b.begin(), b.end(), CMP());
    //reverse(b.begin(), b.end());
    for(auto it : b){cout << it << " ";}
    cout << endl;
}