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

vector<vector<int> > dp;     //背包容量为j时，前i个物品能凑出来的最大价值
vector<int> weight;   //第i个物品的重量
vector<int> value;   //第i个物品的价值
int t, m;  //背包容量， 物品个数

// dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]])

int main()
{
    cin >> t >> m;
    dp.resize(m+1, vector<int>(t+1, 0));
    value.resize(m+1, 0);
    weight.resize(m+1, 0);
    for(int i=0;i<m;i++)
        cin >> weight[i+1] >> value[i+1];
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t;j++){
            if(j >= weight[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[m][t];
}