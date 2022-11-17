#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int v1, v2, w;
    Edge(int v1, int v2, int w):v1(v1), v2(v2), w(w) { }
    bool operator<(Edge& e)
    {
        return w > e.w;
    }
};
class UF
{
public:
    vector<int> parent;
    int c;  //连通分量
    UF(int n)
    {
        c = n;
        parent.resize(n+1);
        for(int i=0;i<=n;++i)
            parent[i] = i;
    }
    int find(int x)
    {
        //cout << "a";
        while(x != parent[x])
            parent[x] = parent[parent[x]];
        return x;
    }
    bool connected(int p, int q)
    {
        cout << "a";
        return find(p) == find(q);
    }
    void connect(int p ,int q)
    {
        int rootP = find(p), rootQ = find(q);
        if(rootP == rootQ)
            return;
        parent[rootP] = parent[rootQ];
        c--;
    }
};
int n, m;
vector<Edge> edges;
//i代表友，i+n代表敌人
int main()
{
    int ans=0;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back(Edge(x, y, z));
    }
    
    sort(edges.begin(), edges.end());
    UF uf(n*2+2);
    
    for(int i=0;i<edges.size();++i)
    {
        Edge it = edges[i];
        if(uf.connected(it.v1, it.v2))
        {
            cout << it.w;
            break;
        }
        int v1 = it.v1, v2 = it.v2, w = it.w;
        uf.connect(v1, v2+n); //将v1和v2的敌人关在一个监狱
        uf.connect(v2, v1+n); //将v2和v1的敌人关在一个监狱
    }
    cout << 0;
}