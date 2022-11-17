#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int n, x;
vector<int> ans;
int dfs(unordered_set<int>& s, int n)
{
    int t=INT32_MAX;
    for(auto& it:s)
    {
        s.erase(it);s.emplace(it^x);
        t = min(t, dfs(s, n));
        s.erase(it^x);s.emplace(it);
    }
    return t;
}
int main()
{
    unordered_set<int> s;
    cin >> n >> x;
    for(int i=0;i<n;++i)
    {
        int m; cin >> m;
        if(s.count(m))
        {
            cout << 0;return 0;
        }
        s.emplace(m);
    }
    cout << dfs(s, 1);
}