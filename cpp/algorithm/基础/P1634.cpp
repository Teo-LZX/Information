#include<iostream>
#include<math.h>
using namespace std;

long long mypow(long long x, long long y)
{
    long long ans = 1;
    for(long long i=0;i<y;i++)
    {
        ans *= x;
    }
    return ans;
}
int main()
{
    long long int x, n;
    cin >> x >> n;
    printf("%lld", pow(1+x, n));
}