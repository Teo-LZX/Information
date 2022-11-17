// #include<iostream>
// #include<vector>
// #include<string>
// #include<map>
// using namespace std;

// class Edge{
//     public:
//         int v;
//         int weight;
//         Edge(int a, int b): v(a), weight(b) {}
// };
// class Vertex{
//     public:
//         int v;
// };
// vector<int> indegree;          //保存每个顶点入度
// map<int, vector<Edge>> graph;

// void show(){
//     for(auto &it : graph){
//         cout << it.first << ": ";
//         for(auto &it2 : it.second){
//             cout << "(" << it2.v << "," << it2.weight << ")"; 
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     indegree.resize(n+1, 0);
//     for(int i=0;i<n;i++){
//         int x, y, z;
//         cin >> x >> y;
//         Edge node(y, z);
//         graph[x].push_back(node);
//     }
//     show();
// }

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

vector<vector<int>> graph;
vector<int> indegree;     //记录每个顶点的入度
vector<int> t;
vector<int> dp;  //前i个任务完成的最大时间
int res=0;

void show(){
    for(auto &it:graph){
        for(auto &it2:it){
            cout << it2 << " ";
        }
        cout << endl;
    }
}
void topology_sort(){
    queue<int> q;
    int flag=0;
    for(int i=1;i<indegree.size();i++)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty()){
        int v = q.front(); q.pop();
        cout << v << " ";
        ++flag;
        dp[v] += t[v];
        res = max(dp[v], res);
        for(int i=0;i<graph[v].size();i++){
            int w = graph[v][i];
            dp[w] = max(dp[w], dp[v]);
            if(!(--indegree[w]))
                q.push(w);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    t.resize(n+1, 0);
    graph.resize(n+1);
    indegree.resize(n+1, 0);
    dp.resize(n+1, 0);
    for(int i=0;i<n;i++){
        int x; cin >> x;    //编号
        cin >> t[x];
        int y; cin >> y;
        while(y){
            indegree[x]++;
            graph[y].push_back(x);
            cin >> y;
        }
    }
    topology_sort();
    cout << res << endl;
    //show();
}