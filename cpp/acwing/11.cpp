#include<iostream>
#include<vector>
using namespace std;

/* f[i] 用来存储背包容积为 ii时的最佳方案的总价值，
cnt[i]为背包容积为 i 时总价值为最佳的方案数*/

long long int mod = 1e7+7;
int main()
{
    int N,V;
    cin >> N >> V;
    vector<int>  v(N+1), w(N+1);
    for(int i=1;i<=N;i++)
        cin >> v[i] >> w[i];
    vector<int> f(V+1, 0), cnt(V+1, 1);
    for(int i=1;i<=N;i++){
        for(int j=V;j>=v[i];j--){
             if(f[j-v[i]] + w[i] > f[j]){         //装上第i个物品后的总价值更高，更新f数组
                f[j] = f[j-v[i]] + w[i];
                cnt[j] = cnt[j-v[i]];                //更新方案数
            }
            else if(f[j-v[i]] + w[i] == f[j])
                cnt[j] = (cnt[j] + cnt[j-v[i]])%mod;
        }
    }
    cout << cnt[V] << endl;
}
