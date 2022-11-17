#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int n,m;

void dfs(int v){
    if(visited[v])
        return;
    cout << v  << " ";
    visited[v] = true;
    for(int i=0;i<graph[v].size();i++){
        int w = graph[v][i];
        dfs(w);
    }
}
void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        int num = q.front(); q.pop();
        cout << num << " ";
        for(int i=0;i<graph[num].size();i++){
            int w = graph[num][i];
            if(!visited[w]){
                visited[w] = true;
                q.push(w);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    graph.resize(n+1);
    visited.resize(n+1, false);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(auto &it : graph)
        sort(it.begin(), it.end());

    dfs(1);
    cout << endl;
    for(int i=0;i<visited.size();i++)
        visited[i] = false;
    bfs(1);
}