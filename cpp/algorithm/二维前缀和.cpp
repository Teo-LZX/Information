#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

int n, m,q;
vector<vector<int>> a;
vector<vector<int>> dp;


int main()
{
    cin >> n >> m >> q;
    a.resize(n+1, vector<int>(m+1, 0));
    dp.resize(n+1, vector<int>(m+1, 0));
    //cout << n << m << endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout << a[i][j] << " "; 
    //     }
    //     cout << endl;
    // }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << sum_pre[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // for(int i=0;i<q;i++){
    //     int x1, x2, y1, y2;
    //     cin >> x1 >> y1 >> x2 >> y2;
    //     points.push_back(Point(x1-1,y1-1,x2,y2));
    // }

    // for(int i=0;i<points.size();i++){
    //     Point p = points[i];
    //     int res = dp[x2][y2] - dp[x1][y2] - dp[x2][y1] + dp[x1][y1];
    //     cout << res << endl;
    // }
    for(int i=1;i<=q;i++)//接受查询 
	{
		int x1,x2,y1,y2;
		cin >>x1>>y1>>x2>>y2;
		cout <<(dp[x2][y2]+dp[x1-1][y1-1]-dp[x1-1][y2]-dp[x2][y1-1])<<endl;
	}

}