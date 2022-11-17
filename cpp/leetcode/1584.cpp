#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class UF{
    public:
        int count;  //连通分量
        vector<int> size;   //每个子集的节点个数
        vector<int> parent;   //父节点
        UF(int n);
        void Union(int p, int q);
        int find(int x);
};
UF::UF(int n){
    parent.resize(n+1);
    size.resize(n+1, 1);
    for(int i=0;i<parent.size();i++)
        parent[i] = i;       //每个节点的祖先都是自己
}
void UF::Union(int p, int q){
    int rootP = find(p);
    int rootQ = find(q);
    if(size[rootP]  > size[rootQ]){
        parent[rootQ] = parent[rootP];
        size[rootP] += size[rootQ];
    }
    else{
        parent[rootP] = parent[rootQ];
        size[rootP] += size[rootQ]; 
    }
    count--;
}
int UF::find(int x){
    while(parent[x] != x){
        x = parent[parent[x]];
    }
    return x;
}

class Edge{
    public:
        int x, y, weight;
        Edge(int x, int y, int weight): x(x), y(y), weight(weight){}
};
class Solution {
public:
   static  bool cmp(const Edge &a, const Edge &b){
        return a.weight < b.weight;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        UF u(points.size());
        int res=0, num=1;
        for(int i=0;i<points.size()-1;++i){
            for(int j=i+1;j<points.size();++j){
                int dis = abs(points[j][1] - points[i][1]) + abs(points[j][0] - points[i][0]);
                edges.emplace_back(Edge(i, j, dis));
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        for(auto &it:edges){
            if(u.find(it.x) != u.find(it.y)){
                u.Union(it.x, it.y);
                res += it.weight;
                num++;
            }
            if(num == points.size())
                break;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};
    cout << solution.minCostConnectPoints(points) << endl;
}