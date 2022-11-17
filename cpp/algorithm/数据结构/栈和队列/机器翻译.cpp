#include<bits/stdc++.h>
using namespace std;

int m, n;
queue<int> q;
set<int> s;

int main()
{
    int ans=0;
    cin >> m >> n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin >> x;
        if(!s.count(x))
        {
            if(q.size() == m)
            {
                s.erase(q.front());
                q.pop();
            }
            q.emplace(x);
            s.insert(x);
            ans++;
        }
    }
    cout << ans;
}