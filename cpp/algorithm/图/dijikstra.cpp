#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

class State{
    public:
        int id;        //图节点编号
        int disFromStart;  //从start到当前节点的距离
        State(int id, int disFromStart):id(id), disFromStart(disFromStart){}
        bool operator<(const State& a) const{         //运算符重载，便于优先级队列的排序
            return disFromStart < a.disFromStart;
        }
};
class Edge{
    public:
        int id;
        int weight;
        Edge(int id, int weight):id(id), weight(weight){}
};
vector<Edge> graph[10000];
int V;
vector<int> dijkstra(int start, vector<Edge> graph[]){
    vector<int> distTo(V+1, INT16_MAX);
    priority_queue<State> q;
    distTo[start] = 0;   //start到start的距离为0
    q.push(State(start, 0));
    while(!q.empty()){
        State curState = q.top(); q.pop();
        int curNodeID = curState.id, curDisFromStart = curState.disFromStart;
        if(curDisFromStart > distTo[curNodeID])
            continue;
        //将curNode的邻接点装入队列
        for(int i=0;i<graph[curNodeID].size();i++){
            int nextNodeID = graph[curNodeID][i].id;
            int distToNextNode = distTo[curNodeID] + graph[curNodeID][i].weight;
            if(distTo[nextNodeID] > distToNextNode){
                distTo[nextNodeID] = distToNextNode;
                q.push(State(nextNodeID, distToNextNode));
            }
        }
    }
    return distTo;
}

int main()
{
    int n, m;
    cin >> n >> m;
    V = n;
    for(int i=0;i<m;i++){
        int x, y, z; cin >> x >> y >> z;
        graph[x].push_back(Edge(y, z));
    }
    vector<int> distTo = dijkstra(1, graph);
    // for(auto &it : distTo)
    //     cout << it << " ";
    cout << distTo[4] << endl;
}