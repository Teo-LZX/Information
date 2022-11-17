#include<bits/stdc++.h>
using namespace std;

int n, m ,s;
class  Edge
{
public:
    Edge() {}
    Edge(int v, int w):v(v), w(w) {}
    int v, w;
};
class State
{
public:
    State(int v, int dist):v(v), dist(dist) {}
    bool operator<(cosnt State& s)
    {
        return dist<s.dist;
    }
    int v, dist;
};
vector<vector<Edge> > graph;

void dijkstra()
{
    priority_queue<State> q;
    vector<int> dist(graph.size()+1, INT_MAX);
    while (!q.empty())
    {
        State curState = q.front();
        int curV = curState.v, curDist = curState.dist;
        if(curDist > dist[curV])
            continue;
        for(int i=0;i<graph[curV].size();++i)
        {
            int distToNextNode = dist[curV] + graph[curV][i].
        }
    }
    
}
int main()
{
    cin >> n >> m >> s;
    graph.resize(n+1);
    for(int i=1;i<=m;++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(Edge(y, z));
    }

}