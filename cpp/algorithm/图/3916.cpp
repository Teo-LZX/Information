#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> visited;

void show(){
    for(int i=1;i<graph.size();i++){
        for(int j=0;j<graph[i].size();j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
void dfs(int v, int d){             //v是当前遍历的节点， d是从哪个节点开始遍历的
    if(visited[v])
        return;
    visited[v] = d;
    //cout << v << " " << "  d=" << d << endl;
    for(int i=0;i<graph[v].size();i++){
        int w =  graph[v][i];
            dfs(w, d);
    }
}
int main()
{
    cin >> n >> m;
    graph.resize(n+1);
    visited.resize(n+1, 0);
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        //graph[x].push_back(y);
        graph[y].push_back(x);   //要反向建边
    }
    for(int i=n;i > 0;i--){
       //cout <<  endl << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        dfs(i, i);
    }
    for(int i=1;i<visited.size();i++)
        cout << visited[i] << " ";
    cout << endl; 
    //show();
}
