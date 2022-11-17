#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int v;   //箱子容量
int n;   //物品个数
vector<int> vol;  //每个物品体积
vector<int> dp;   //背包容量为i时，能装的最大体积

// dp[i] = max(dp[i], dp[i-vol[i]] + vol[i])

int main()
{
    cin >> v;
    cin  >> n;
    vol.resize(n+1, 0);
    dp.resize(v+1, 0);
    for(int i=1;i<=n;i++)
        cin >> vol[i];
    for(int i=1;i<=n;i++){
       for(int j=v;j>=0;j--){
           if(j >= vol[i])
                dp[j] = max(dp[j-vol[i]] + vol[i], dp[j]);
       }
    }
    // cout << endl;
    // for(auto &it : dp){
    //     cout << it << " ";
    // }
    cout << v-dp[v];
}