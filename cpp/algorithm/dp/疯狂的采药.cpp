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



long long t, m;
vector<long long> ttime, value;
vector<long long> dp;
int main()
{
    cin >> t >> m;
    ttime.resize(m+1, 0);
    value.resize(m+1, 0);
    dp.resize(t+1, 0);
    for(int i=0;i<m;i++)
        cin >> ttime[i+1] >> value[i+1];
    // for(int i=1;i<=m;i++){
    //     for(int j=t;j>=0;j--){
    //         for(int k=0;j>=k*ttime[i];k++){
    //             dp[i][j] = max(dp[i][j], dp[i-1][j-k*ttime[i]] + k*value[i]);
    //         }
    //     }
    // }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=t;j++){
    //         if(j>=ttime[i])
    //             dp[i][j] = max(dp[i-1][j], dp[i][j-ttime[i]] + value[i]);
    //         else
    //             dp[i][j] = dp[i-1][j];
    //     }
    // }
    for(int i=1;i<=m;i++){
        for(int j=ttime[i];j<=t;j++){
            dp[j] = max(dp[j], dp[j-ttime[i]] + value[i]);
        }
    }
    cout << dp[t];
    return 0;
}