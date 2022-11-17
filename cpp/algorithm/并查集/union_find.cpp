#include<iostream>
#include<vector>
#include<string>
using namespace std;

class UF{
    private:
        int connecting_componets;
        vector<int> parent;
    public:
        UF(int n);
        void Union(int p, int q);
        int find(int x);
        int count();
};
UF:: UF(int n){
    parent.resize(n+1);
    for(int i=1;i<n;i++){
        parent[i] = i;
    }
}
void UF::Union(int p, int q){
    int rootP = find(p);
    int rootQ = find(q);
    parent[rootP] = parent[rootQ];
    connecting_componets--;
}
int UF::find(int x){
    while(parent[x] != x){
        x = parent[parent[x]];
    }
    return x;
}
int UF::count(){
    return connecting_componets;
}

int main()
{
    
}