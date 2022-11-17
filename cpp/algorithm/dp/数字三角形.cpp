#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

int arr[2000][2000];
//vector<vector<int>> dp;
vector<vector<int>> memo;
int r;

int dp(int i, int j)
{
    //cout << i << "  " <<  j << endl;
    if(i<0 || j>i)
        return -999;
    if(i == 1 &&  j == 1)
        return arr[1][1];
    if(memo[i][j] != -1)
        return memo[i][j];
    memo[i][j] = max(dp(i-1, j), dp(i-1, j-1)) + arr[i][j];
    // if(i == 2 && j == 2)
    //     cout << "hello world" << memo[i][j] << endl;
    //cout << memo[i][j] << endl;
    return memo[i][j];
}
int main()
{
    cin >> r;
    //dp.resize(r+1, vector<int>(r+1, 0));
    memo.resize(r+1, vector<int>(r+1, -1));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            cin >> arr[i][j];
        }
    }
    int ans = -1;
    for(int i=1;i<=r;i++){
        //cout << "i=" << i  << "  r=" << r << endl;
        ans = max(ans, dp(r, i));
    }
    cout << ans << endl;
    // cout << endl;
    // for(int i=1;i<=r;i++){
    //     for(int j=1;j<=i;j++){
    //         cout <<  arr[i][j];
    //     }
    //     cout << endl;
    // }

}