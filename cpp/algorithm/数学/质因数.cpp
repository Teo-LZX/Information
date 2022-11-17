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

long long  n;
int main()
{
    scanf("%d", &n);
    for(long i=2; ;++i){
        if(n%i == 0){
            printf("%ld", n/i);
            break;
        }
    }
}