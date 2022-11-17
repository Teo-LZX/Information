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

int m ,n;
vector<int> dp;
vector<int> score, ttime;

int main()
{
    cin >> m >> n;
    dp.resize(m+1, 0);
    score.resize(n+1, 0);
    ttime.resize(n+1, 0);
    for(int i=1;i<=n;i++)
        cin >> score[i] >> ttime[i];
    for(int i=1;i<=n;i++){
        for(int j=ttime[i];j<=m;j++){
            dp[j] = max(dp[j], dp[j-ttime[i]] + score[i]);
        }
    }
    cout << dp[m];
}