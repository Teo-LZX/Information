#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int n,m;
class UF
{
public:
    vector<int> parent;
    vector<int> size;
    int c;
    UF(int n)
    {
        parent.resize(n+1);
        size.resize(n+1, 0);
        for(int i=0;i<n+1;++i)
            parent[i] = i;
        c = n;
    }
    int find(int x)
    {
        while(x != parent[x])
            x = parent[parent[x]];
        return x;
    }
    void Union(int p, int q)
    {
        int rootP = find(p), rootQ = find(q);
        if(size[rootP] > size[rootQ])
        {
            parent[rootQ] = parent[rootP];
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = parent[rootQ];
            size[rootQ] += size[rootP];
        }
        c -= 1;
    }
    bool connected(int p, int q)
    {
        int rootP = find(p), rootQ = find(q);
        return rootP == rootQ;
    }
    int count()
    {
        return c;
    }
};
class Edge
{
    public:
        int x, y, t;
        Edge(int x, int y, int t):x(x), y(y), t(t) {}
        bool operator<(const Edge& e) const
        {
            return t < e.t;
        }
};
vector<Edge> edges;
vector<int> ts;
int main()
{
    cin >> n >> m;
    UF uf(n);
    for(int i=0;i<m;++i)
    {
        int x, y, t;
        cin >> x >> y >> t;
        edges.push_back(Edge(x, y, t));
    }
    sort(edges.begin(), edges.end());
    for(int i=0;i<edges.size();++i)
    {
        int x = edges[i].x, y = edges[i].y;
        if(!uf.connected(x, y))
        {
            uf.Union(x, y);    //修复此公路
            ts.push_back(edges[i].t);
        }
    }
    if(uf.c > 1)
    {
        cout << "-1";
        return 0;
    }
    int ans =0;
    for(auto &it:ts)
        ans = max(ans, it);
    cout << ans;
    return 0;
}