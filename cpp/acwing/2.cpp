#include<iostream>
#include "vector"
using namespace std;
//01

/* 有 N 件物品和一个容量为 V 的背包，每件物品有各自的价值且只能被选择一次，要求在有限的背包容量下，装入的物品总价值最大。*/

/*状态f[j]定义：N件物品，背包容量下的最优解。

注意枚举背包容量j必须从m开始。*/

// *** 状态转移方程：F[j] = max(F[j], F[j-v[i]] + w[i])

int main()
{
    int N, V;
    cin >> N >> V;
    vector<int> v(N+1), w(N+1);
    for(int i=1;i<=N;i++) {
        cin >> v[i] >> w[i];
    }
    vector<int> F(V+1, 0);
    for(int i=1;i<=N;i++) {
        for(int j=V;j>0;j--) {
            if(j>=v[i]) 
                F[j] = max(F[j], F[j-v[i]] + w[i]);
        }
    }
    cout << F[V] << endl;
}