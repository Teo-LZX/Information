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

class Point
{
public:
    long long x, y, z;
    Point(long long x, long long y, long long z):x(x), y(y), z(z) {}
};
int T;
long long n, h, r;
long long x, y, z;
vector<Point> points;
vector<vector<int> > graph;
vector<bool> vis;
bool flag = false;
void dfs(int v)
{
    if(vis[v])
        return;
    vis[v] = true;
    //cout << "@" << v << endl;
    if(points[v].z + r >= h)
    {
        flag = true;
        return;
    }
    for(int i=0;i<graph[v].size();++i)
    {
        int w = graph[v][i];
        dfs(w);
    }
}
int main()
{
    cin >> T;
    for(int k=0;k<T;++k)
    {
        cin >> n >> h >> r;
        graph.clear();
        graph.resize(n+1);
        flag = false;
        vis.resize(n+1, false);
        points.clear();
        for(int i=0;i<n;i++)
        {
            cin >> x >> y >> z;
            points.push_back(Point(x, y, z));
        }
        for(int i=0;i<points.size()-1;++i)
        {
            for(int j=i+1;j<points.size();++j)
            {
                Point a = points[i], b = points[j];
                double dis = sqrt(static_cast<double>(pow(a.x-b.x, 2)) + static_cast<double>(pow(a.y-b.y, 2)) + static_cast<double>(pow(a.z-b.z, 2)));
                //cout << "dis=" << dis << "  r=" << r << endl;
                if(dis <= static_cast<double>(2*r))
                {
                    //cout << "hello " << i << "  " << j << endl;
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        // cout << "--------------" << points.size() << endl;
        // for(int i=0;i<graph.size();i++)
        // {
        //     for(int j=0;j<graph[i].size();j++)
        //     {
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "--------------" << endl;
        for(int i=0;i<points.size();++i)
        {
            //cout << "hello" << endl;
            if(points[i].z-r <= 0)
            {
                dfs(i);
            }
            if(flag)
                break;
        }
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

}