#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class UF{
    public:
        int count;
        vector<int> parent;
        vector<int> size;
        UF(int n);
        void Union(int p, int q);
        bool connected(int p, int q);
        int find(int x);
};
UF::UF(int n){
    parent.resize(n+1);
    size.resize(n+1, 1);
    for(int i=0;i<parent.size();i++)
        parent[i] = i;
}
void UF::Union(int p, int q){
    int rootP = find(p), rootQ = find(rootQ);
    if(size[rootP] > size[rootQ]){
        parent[rootQ] = parent[rootP];
        size[rootP] += size[rootQ];
    }
    else{
        parent[rootP] = parent[rootQ];
        size[rootQ] += parent[rootP];
    }
}
bool UF::connected(int p, int q){
    return find(p) == find(q);
}
int UF::find(int x){
    while(parent[x] != x)
        x = parent[parent[x]];
    return x;
}
class EdgeNode{
    public:
        int  v, weight;
        EdgeNode(int v, int weight): v(v), weight(weight){}
};
class Graph{
    public:
        vector<vector<EdgeNode>> G;
        vector<int> indegree;
        Graph(int n);
        void add_edge(int x, int y, int weight);
        bool topology_sort();
};
Graph::Graph(int n){
    G.resize(n);
    indegree.resize(n, 0);
}
void Graph::add_edge(int x, int y, int weight){
    G[x].emplace_back(EdgeNode(y, weight));
    indegree[y]++;
}
bool Graph::topology_sort(){
    queue<int> q;
    int flag=0;
    for(int i=0;i<indegree.size();i++)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty()){
        int v = q.front(); q.pop();
        flag++;
        for(int i=0;i<G[v].size();i++){
            int w = G[v][i].v;
            if(--(indegree[w]) == 0){
                q.push(w);
            }
        }
    }
    if(flag<G.size())
        return false;
    return true;
}
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph(numCourses);
        for(auto &it : prerequisites){
            graph.add_edge(it[0], it[1], 1);
        }
        return graph.topology_sort();
    }
};
int main()
{
    Solution solution;
    
}