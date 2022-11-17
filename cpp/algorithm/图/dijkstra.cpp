#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

class Edge{
    public:
        int v, weight;
        Edge(int v, int weight):v(v), weight(weight){}
            
};
class State{
    public:
        int v, distFromStart;
        State(int v, int distFromStart):v(v), distFromStart(distFromStart){}
        bool operator<(const State& s)const {
            return distFromStart < s.distFromStart;
        }
};
class Graph{
    public:
        int n, m;
        map<int, vector<Edge>> graph;
        Graph(int n, int m):n(n), m(m){
        }
        void add_edge(int x, int y, int weight){
            graph[x].push_back(Edge(y, weight));
        }
        int dijkstra(int start, int end){
            priority_queue<State> q;      // 优先级队列
            vector<bool> visited(n, false);   //标志访问数组
            vector<int> dist(n, INT16_MAX);
            dist[start] = 0;
            q.push(State(start, 0));
            while(!q.empty()){
                State curState = q.top(); q.pop();
                int curNode = curState.v, curDistFromStart = curState.distFromStart;
                if(curDistFromStart > dist[curNode])
                    continue;
                for(int i=0;i<graph[curNode].size();i++){
                    int nextNode = graph[curNode][i].v;
                    int distToNextNode = dist[curNode] + graph[curNode][i].weight;
                    if(distToNextNode < dist[nextNode]){
                        dist[nextNode] = distToNextNode;
                        q.emplace(State(nextNode, distToNextNode));
                    }
                }
            }
            int res=0;
            for(auto &it:dist)
                res += it;
            return dist[end];
        }
};
int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    for(int i=0;i<m;i++){
        int x, y, weight;
        cin >> x >> y >> weight;
        g.add_edge(x, y, weight);
    }
    cout << g.dijkstra(3, 4) << endl;
}