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
vector<int> v, w;
vector<vector<int> > dp;  //前i个物品， 有j元钱时，能够买到的价格*重要度最大值

int main()
{
    cin >> n >> m;
    v.resize(m+1, 0);
    w.resize(m+1, 0);
    dp.resize(m+1, vector<int>(n+1));
    for(int i=1; i<=m;i++)
        cin >> v[i] >> w[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j>=v[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]] + v[i]*w[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[m][n];
}