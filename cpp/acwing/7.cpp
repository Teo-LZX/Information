#include<iostream>
#include<vector>
using namespace std;

/* 有 N 种物品和一个容量是 V 的背包。
物品一共有三类：
第一类物品只能用1次（01背包）；
第二类物品可以用无限次（完全背包）；
第三类物品最多只能用 si 次（多重背包）；
每种体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。*/


int main()
{
    int N,V;
    cin >> N >> V;
    vector<int>  v(N+1), w(N+1), s(N+1);
    for(int i=1;i<=N;i++)
        cin >> v[i] >> w[i] >> s[i];
    
}