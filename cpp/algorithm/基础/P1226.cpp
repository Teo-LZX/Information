#include<iostream>
using namespace std;

int main()
{
    long long a,b,p,x;
    cin >> a >> b >> p;
    x = b;
    long long  ans = 1, base = a;
    while(b)
    {
        if(b & 1)
            ans = ans*base % p;
        base = base*base % p;
        b >>= 1;
    }
    printf("%lld^%lld mod %lld=%lld", a, x, p, ans);
}