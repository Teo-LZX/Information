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

int n, m;
vector<int> value;  //第i种菜的价格
vector<int> dp;   //j块钱的点菜方法种数
// dp[j] =  dp[j] + dp[j-value[i]]
int main()
{
    cin >> n >> m;
    value.resize(n+1, 0);
    dp.resize(m+1, 0);
    for(int i=0;i<n;i++)
        cin >> value[i+1];
    dp[0] = 1;  //没得钱时不点菜也是一种方法
    for(int i=1;i<=n;i++){
        for(int j=m;j>=value[i];j--){
            dp[j] = dp[j] + dp[j-value[i]];
        }
    }   
    cout << dp[m];
}