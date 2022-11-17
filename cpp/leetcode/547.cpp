#include<iostream>
#include<vector>
#include<string>
using namespace std;

class UF{
    public:
        int c;
        vector<int> parent;
        vector<int> size;
        UF(int n);
        int find(int x);
        void Union(int p, int q); 
        int count();
};
UF:: UF(int n){
    parent.resize(n+1);
    size.resize(n+1, 1);
    for(int i=0;i<parent.size();i++)
        parent[i] = i;
    c = n;
}
int UF::find(int x){
    while(parent[x] != x)
        x = parent[parent[x]];
    return x;
}
void UF::Union(int p, int q){
    int rootP = find(p), rootQ = find(q);
    if(parent[rootP] == parent[rootQ])
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
int UF::count(){
    return c;
}
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UF uf(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1)
                    uf.Union(i, j);
            }
        }
        return uf.count();
    }
};
int main()
{}