#include<bits/stdc++.h>
using namespace std;

int k, p, n, m;
list<int> l;
set<int> flag;

int main()
{
    cin >> n;
    vector<list<int>::iterator> pos(n+99999);
    l.push_back(1);
    pos[1] = l.begin();
    
    for(int i=2;i<n+1;++i)
    {
        scanf("%d %d", &k, &p);
        // list<int>::iterator it = l.begin();
        // while(*it != k)
        //     it++;
        if(p==0)
            pos[i] = l.insert(pos[k], i);
        else
        {
            auto nextIter = next(pos[k]);
            pos[i] = l.insert(nextIter, i);
        }
            
    }
    cin >> m;
    for(int i=1;i<=m;++i)
    {
        int x;
        cin >> x;
        if(!flag.count(x))
        {
            l.erase(pos[x]);
            flag.insert(x);
        }
    }
   
    for(auto &it:l)
        cout << it << " ";
    cout << endl;
    
}