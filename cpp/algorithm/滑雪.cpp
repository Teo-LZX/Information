#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

int r, c;
vector<vector<int>> g;
vector<vector<int>> vis;
vector<int> dir_x = {1, -1, 0, 0};
vector<int> dir_y = {0, 0, 1, -1};


int dp(int i, int j)
{
    if(vis[i][j]!=0)
        return vis[i][j];
    vis[i][j] = 1;
    for(int k=0;k<4;k++){
        int next_i = i + dir_x[k];
        int next_j = j + dir_y[k];
        if(next_i>0 && next_j>0 && next_i<=r && next_j<=c && g[i][j] > g[next_i][next_j]){
            vis[i][j] = max(dp(next_i, next_j)+1, vis[i][j]);
        }
    }
    return vis[i][j];
}
int main()
{
    cin >> r >> c;
    g.resize(r+1, vector<int>(c+1, 0));
    vis.resize(r+1, vector<int>(c+1, 0));
    int ans = -999;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin >> g[i][j];
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            ans = max(ans, dp(i, j));
        }
    }
    cout << ans;
}