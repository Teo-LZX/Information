#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> annex_w;
vector<vector<int>> annex_v;
vector<int> mains_v;
vector<int> mains_w;
int n, m;

int main()
{
    cin >> n >> m;
    annex_w.resize(m+1, vector<int>(3, 0));
    annex_v.resize(m+1, vector<int>(3, 0));
    mains_w.resize(m+1, 0);
    mains_v.resize(m+1, 0);
    for(int i=1;i<=m;++i)
    {
        int p, q, index;
        cin >> p >> q >> index;
        if(index==0)
        {
            mains_v[i] = p;   //价格
            mains_w[i] = q;  //重要度
        }
        else
        {
            
        }
    }
}