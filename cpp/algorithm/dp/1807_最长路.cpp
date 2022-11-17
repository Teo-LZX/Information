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
        long int id, weight;
        Edge(long int id, long int weight):id(id), weight(weight){}
};
class State{
    public:
        int id, distFromStart;
        State(int id, int distFromStart):id(id), distFromStart(distFromStart){}
        bool operator<(const State &a) const {
            return distFromStart > a.distFromStart;
        }
};

vector<Edge> graph[10000];
int n, m;
vector<int> dijkstra(int start){
    vector<int> distTO(n+1, INT16_MIN);
    distTO[start] = 0;
    priority_queue<State> q;
    q.push(State(start, 0));
    while(!q.empty()){
        State curState = q.top(); q.pop();
        int curNodeID = curState.id, curDisFromStart = curState.distFromStart;
        if(curDisFromStart < distTO[curNodeID])
            continue;
        for(int i=0;i<graph[curNodeID].size();i++){
            int nextNodeID = graph[curNodeID][i].id;
            int distToNextNode = distTO[curNodeID] + graph[curNodeID][i].weight;
            if(distTO[nextNodeID] < distToNextNode){
                distTO[nextNodeID] = distToNextNode;
                q.push(State(nextNodeID, distToNextNode));
            }
        }
    }
    return distTO;
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x, y, z; cin >> x >> y >> z;
        graph[x].push_back(Edge(y, z));
    }
    vector<int> distTo = dijkstra(1);
    cout << distTo[n] << endl;
}