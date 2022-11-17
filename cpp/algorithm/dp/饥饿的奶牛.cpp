#include<bits/stdc++.h>
using namespace std;

//线性动态规划
int n;
vector<int > f[3000001];   //f[j]表示以j结尾的区间  
int dp[3000001];         //dp[j] = max(dp[j-1], dp[j-1] + j - i + 1)

int main()
{
    cin >> n;
    int x, y;
    int m=0;
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        cin >> x >> y;
        m = max(m, y);
        f[y].push_back(x);
    }
    for(int i=1;i<=m;++i)
    {
        dp[i] = dp[i-1];
        for(int j=0;j<f[i].size();++j)
        {
            int right = i, left = f[i][j]-1;
            dp[i] = max(dp[i], dp[left] + right-left); 
        }
    }
    cout << dp[m];
}