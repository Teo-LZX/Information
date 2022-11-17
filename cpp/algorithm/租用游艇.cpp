#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

int n;
vector<vector<int>> r;
vector<int> dp;

int main()
{
    cin >> n;
    r.resize(n+1, vector<int>(n+1, 0));
    dp.resize(n+1, 0);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin >> r[i][j];
            cout << "dp[i]=" << dp[i] << " r[i][j]=" << r[i][j] << endl;
            dp[i] = max(dp[i], dp[i]+r[i][j]);
        }
    }
    cout << dp[n];
}