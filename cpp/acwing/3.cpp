#include<iostream>
#include<vector>
using namespace std;
//完全背包问题
/* 有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。

第 i 种物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。*/

// f[j]表示背包容量为j时的最大价值
//状态转移方程： f[j] = max(f[j], f[j-v[i]] + w[i], f[j-2*v[i]] + 2*w[i], ..., f[j-k*v[i]] + k*w[i])

int main()
{
    //cout << "hello" << endl;
    int N, V;
    cin >> N>> V;
    vector<int> v(N+1), w(N+1);
    vector<int> f(V+1);
    for(int i=1;i<=N;i++)
        cin >> v[i] >> w[i];
    for(int i=1;i<=N;i++){
        //注：01背包一维数组要倒着遍历，完全背包一维数组要正着遍历
        for(int j=v[i];j<=V;j++){
           // for(int k=0;j>=k*v[i];k++){
                f[j] = max(f[j], f[j-v[i]] + w[i]);
            //}
        }
    }
    cout << f[V] << endl;
}