#include<bits/stdc++.h>
using namespace std;

int n,x;
vector<int> dp;
vector<int> lose;
vector<int> win;
vector<int> use;
int main()
{
    cin >> n >> x;
    dp.resize(x+1, 0);
    lose.resize(n+1);
    win.resize(n+1);
    use.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin >> lose[i] >> win[i] >> use[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=x;j>=0;--j)        //压缩成一维背包要倒着遍历
        {
            if(j>= use[i])
                dp[j] = max(dp[j] + lose[i], dp[j-use[i]] + win[i]);
            else
                dp[j] += lose[i];
        }
    }
    cout << static_cast<long long>(dp[x]) * 5;
}