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

int n, w; //W表示总钱数，n为希望购买物品的个数
int min_v=0, max_v=0;
vector<int> v;   //价格
vector<int> p;   //重要度

int main()
{
    int f[101][1000001];  //前i个物品，有j元钱，能买到的最大
    cin >> n >> w;
    v.resize(n+1, 0);
    p.resize(n+1, 0);
    for(int i=0;i<101;i++)
        for(int j=0;j<1000001;j++)
            f[i][j] = 0;
    
    for(int i=1;i<=n;i++)
        cin >> v[i] >> p[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(j >= v[i])
                f[i][j] = max(f[i-1][j], f[i-1][j-v[i]] + p[i]);
            else
                f[i][j] = f[i-1][j];
        }
    }
    cout << f[n][w];
}