#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
int n;
int c[10001], p[10001], t[10001];  //美学值，次数，时间
int dp[10001];
int h1, h2, m1, m2;
int get_time()
{
    return 60*(h2-h1) + m2-m1;
}
int main()
{
    scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &n);
    int T = get_time();
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++)
        cin >> t[i] >> c[i] >> p[i];
    //cout << T << endl;
    for(int i=1;i<=n;++i){
        for(int j=T;j>=t[i];--j){   
            for(int k=0;p[i]==0 || k<=p[i];++k){
                    dp[j] = max(dp[j], dp[j-t[i]] + c[i]);
            }
        }
    }   
    cout << dp[T];
}