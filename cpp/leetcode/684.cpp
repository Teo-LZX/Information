#include<iostream>
#include<vector>
#include<string>
using namespace std;

class UF{
    public:
        int c;
        vector<int> parent;
        vector<int> size;
        UF(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            c = n;
            for(int i=0;i<parent.size();i++)
                parent[i] = i;
        }
        int find(int x){
            while(parent[x] != x)
                x = parent[parent[x]];
            return x;
        }
        void Union(int p, int q){
            int rootP = find(p), rootQ = find(q);
            if(rootP == rootQ)
                return;
            if(size[rootP] > size[rootQ]){
                parent[rootQ] = parent[rootP];
                size[rootP] += size[rootQ];
            }
            else{
                parent[rootP] = parent[rootQ];
                size[rootQ] += size[rootP];
            }
            c--;
        }
        bool connected(int p, int q){
            int rootP = find(p), rootQ = find(q);
            if(rootP == rootQ)
                return true;
            return false;
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UF uf(1001);
        vector<int> res;
        for(auto &it : edges){
            if(!uf.connected(it[0], it[1]))
                uf.Union(it[0], it[1]);
            else{
                res = it;
                return res;
            }
        }
    }
};
int main()
{}