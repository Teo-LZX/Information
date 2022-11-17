#include<bits/stdc++.h>
using namespace std;

//完全背包问题
int n, h;
int p[6000], c[6000];
int dp[90000];   //dp[i]表示干草重量为i时付的最少的钱
int main()
{
    cin >> n >> h;
    memset(p, 0, sizeof(p));
    memset(c, 0, sizeof(c));
    memset(dp, 1e6, sizeof(dp));
    dp[0] = 0;             //dp[0]必须为0,不然后面根本无法求min最小，含义：买0kg干草花的钱为0
    for(int i=1;i<=n;++i)
        cin >> p[i] >> c[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=p[i];j<=h+5000;++j)
        {
            dp[j] = min(dp[j], dp[j-p[i]] + c[i]);
        }
    }
    int ans = 1e9;
    for(int i=h;i<=h+5000;++i)
        ans = min(ans, dp[i]);
    cout << ans;
}