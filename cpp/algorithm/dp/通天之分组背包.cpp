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
#include<cstring>
using namespace std;

int m,n;
vector<int> v[2000];
vector<int> w[2000];
int dp[2000][2000];
int a, b, c;
int zu = 0, res=0;
int main()
{
    cin >> m >> n;
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++){
        cin >> a >> b >> c;
        v[c].push_back(b);
        w[c].push_back(a);
        zu = max(zu, c);
    }
    // for(int i=1;i<=3;i++){
    //     for(auto &it:w[i])
    //         cout << it << " ";
    //     cout << endl;
    // }
    //cout << zu << endl;
    for(int i=1;i<=zu;i++){         //第i组
        for(int j=1;j<=m;j++){   //背包容量为j时
            for(int k=0;k<v[i].size();k++){  //第i组的第k个物品
                if(j >= w[i][k]){
                     dp[i][j] = max(dp[i][j], dp[i-1][j-w[i][k]] + v[i][k]);
                }
            }
        }
    }
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
}