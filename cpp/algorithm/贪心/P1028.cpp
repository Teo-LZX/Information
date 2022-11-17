#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class farmer
{
public:
    int price, milk;
    farmer(int price, int milk):price(price), milk(milk) {}
    bool operator<(farmer& p)
    {
        return price < p.price;
    }
};
int main()
{
    int n, m, ans=0;
    vector<farmer> farmers;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        farmers.push_back(farmer(a, b));
    }
    sort(farmers.begin(), farmers.end());
    for(int i=0;i<farmers.size() && n > 0;i++)
    {
        if(n>farmers[i].milk)
        {
            n -= farmers[i].milk;
            ans += farmers[i].milk * farmers[i].price;
        }
        else
        {
            ans += farmers[i].price * n;
            n = 0;
        }
    }
    cout << ans;
}