#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> arr(N+1), sub(N+1);
    sub[0] = arr[0] = 0;
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];
        sub[i] = sub[i-1] + arr[i];   //sub[i]表示arr前i个数之和
    } 
    
    int ans=0, flag=0;
    for(register int i=1;i<=N;i++)
    {
        for(register int j=N;j-4>i+ans-1;j-=4)
        {
            if((sub[j] - sub[i-1])%7 == 0)    //sub[j] - sub[i-1]表示arr[i, j]的和
            {
                if(j-i+1 > ans)
                    ans = j-i+1;
            }
            if((sub[j-1] - sub[i-1])%7 == 0)    
            {
                if(j-i > ans)
                    ans = j-i;
            }
            if((sub[j-2] - sub[i-1])%7 == 0)   
            {
                if(j-i-1 > ans)
                    ans = j-i-1;
            }
            if((sub[j-3] - sub[i-1])%7 == 0)   
            {
                if(j-i-2 > ans)
                    ans = j-i-2;
            }
        }
    }
    printf("%lld", ans);
}

