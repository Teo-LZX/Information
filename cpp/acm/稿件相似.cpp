#include<iostream>
#include<vector>
using namespace std;

long long n, p;
vector<int> f;
vector<vector<int> > graph;

int main()
{
    cin >> n >> p;
    f.resize(n+2);
    int ans=0;
    for(int i=1;i<=n;++i)
       cin >> f[i];
    for(int i=1;i<n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            int x = (f[i]+f[j])*(f[i]*f[i]+f[j]*f[j])%p;
            if(x==1)
                 ++ans;//graph.push_back(vector<int>{i, j});}
        }
    }
    // for(auto &it:graph)
    //     cout << it[0] << "," << it[1] << endl;
    cout << ans;
}