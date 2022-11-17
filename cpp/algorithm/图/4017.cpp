#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

const int mod = 80112002; //定义最终答案mod的值 
class graph{
    private:
        vector<vector<int>> g;
        vector<int> indegree;
        vector<int> outdegree;
        vector<int> res;
    public:
        graph(int n){
            g.resize(n+1);
            res.resize(n+1, 0);
            indegree.resize(n+1, 0);
            outdegree.resize(n+1, 0);
        }
        void add_edge(int a, int b){
            g[a].push_back(b);
            indegree[b]++;
            outdegree[a]++;
        }
        void topology_sort();
        void show();
        int result(){
            for(int i=1;i<outdegree.size();i++){
                if(outdegree[i] == 0)
                    return res[i]%mod;
            }
            return res[res.size()-1];
        }
};
void graph::topology_sort(){
    queue<int> q;
    for(int i=1;i<indegree.size();i++)
        if(indegree[i] == 0)
            q.push(i);
    res[q.front()] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        //cout << v << " ";
        for(int i=0;i<g[v].size();i++){
            int w = g[v][i];
            res[w] = (res[w] + res[v])%mod;
            if(!(--indegree[w]))
                q.push(w);
        }
    }
}
void graph::show(){
    for(int i=1;i<g.size();i++){
        for(int j=0;j<g[i].size();j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    graph G(n);
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        G.add_edge(x, y);
    }
    G.topology_sort();
    cout  << G.result() << endl;   
}