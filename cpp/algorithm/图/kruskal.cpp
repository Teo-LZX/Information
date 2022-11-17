// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// using namespace std;

// class UF{               //并查集类
//     protected:
//         int connecting_componets;
//         vector<int> parent;
//     public:
//         UF(int n);
//         UF(){}
//         void Union(int p, int q);
//         int find(int x);
//         int count();
// };
// UF:: UF(int n){
//     parent.resize(n+1);
//     for(int i=1;i<n;i++){
//         parent[i] = i;
//     }
// }
// void UF::Union(int p, int q){
//     int rootP = find(p);
//     int rootQ = find(q);
//     parent[rootP] = parent[rootQ];
//     connecting_componets--;
// }
// int UF::find(int x){
//     while(parent[x] != x){
//         x = parent[parent[x]];
//     }
//     return x;
// }
// int UF::count(){
//     return connecting_componets;
// }
// class edge{     //边节点类
//     public:
//         int v;
//         int weight;
//         edge(int v, int weight):v(v), weight(weight){}
// };

// bool cmp(edge &a, edge &b){
//     return a.weight < b.weight;
// }

// class graph{    //图类
//     public:
//         vector<vector<edge>> g;
//         UF u;
//         graph(int n);
//         void add_edge(int p, int q, int w);
//         void kruskal();
// };
// graph::graph(int n){
//     g.resize(n+1);
// }
// void graph::add_edge(int p, int q, int w){
//     edge e(q, w);
//     edge e2(p, w);
//     g[p].push_back(e);
//     g[q].push_back(e2);          //建立无向图
// }
// void graph::kruskal(){
//     for(int i=1;i<g.size();i++){
//         sort(g[i].begin(), g[i].end(), cmp);
//     }

// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     graph G(n);
//     UF u(n);
//     for(int i=0;i<m;i++){
//         int x, y, z;
//         cin >> x >> y >> z;
//         G.add_edge(x, y, z);
//         u.Union(x, y);
//     }
//     G.kruskal();
// }

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class UF{
    private:
        int connecting_componets;
        vector<int> parent;
    public:
        UF(int n);
        void Union(int p, int q);
        int find(int x);
        int count();
};
UF:: UF(int n){
    parent.resize(n+1);
    for(int i=1;i<n;i++){
        parent[i] = i;
    }
}
void UF::Union(int p, int q){
    int rootP = find(p);
    int rootQ = find(q);
    parent[rootP] = parent[rootQ];
    connecting_componets--;
}
int UF::find(int x){
    while(parent[x] != x){
        x = parent[parent[x]];
    }
    return x;
}
int UF::count(){
    return connecting_componets;
}

int n, m;
int res=0;

class edge{
    public:
        int p, q;
        int weight;
        edge(int p, int q, int weight): p(p), q(q), weight(weight){}
};
vector<edge> edges;
bool cmp(edge a, edge b){
    return a.weight < b.weight;
}
void kruskal(UF &u){
    sort(edges.begin(), edges.end(), cmp);
    int flag=0;
    for(auto &it : edges){
        if(flag == n-1)
            break;
        int p = it.p, q = it.q;
        if(u.find(p) != u.find(q)){
            u.Union(p, q);
            res += it.weight;
        }
        flag++;
    }
}
int main()
{
    cin >> n >> m;
    UF u(n);
    for(int i=0;i<m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        edge e(x, y, z);
        edges.push_back(e);
    }
    kruskal(u);
    cout << res << endl;
}