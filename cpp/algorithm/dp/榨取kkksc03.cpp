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

int n, M ,T;
vector<int> m, t;
vector<vector<int> > dp;
int main()
{
    cin >> n >> M >> T;
    m.resize(n+1, 0);
    t.resize(n+1, 0);
    dp.resize(M+1, vector<int>(T+1, 0));
    for(int i=1;i<=n;i++)
        cin >> m[i] >> t[i];
    for(int i=1;i<=n;i++){
        for(int j=M;j>=m[i];--j){
            for(int k=T;k>=t[i];--k){
                dp[j][k] = max(dp[j][k] , dp[j-m[i]][k-t[i]] + 1);
            }
        }
    }
    cout << dp[M][T];
}