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

typedef long long ll;
ll s, n, d;
vector<ll> w;
vector<ll> v;
vector<ll> dp;
int main()
{
    cin >> s >> n >> d;
    w.resize(d+1, 0);
    v.resize(d+1, 0);
    dp.resize(10000001, 0);
    for(int i=1;i<=d;i++)
        cin >> w[i] >> v[i];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=d;i++){        // 前i种债券
            for(int j=w[i];j<=s;j++){   // 有j元资产
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);  // 有j元资产时能够得到的最大利息
            }
        }
         s += dp[s];
    }
    cout << s;
}