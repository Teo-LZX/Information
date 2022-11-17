#include "stdio.h"
int main()
{
    int n,i,sum=0;//定义一个存放因子和的变量，以及需要判断的数n，和循环条件用到的i
    printf("请输入需要判断的数：");
    scanf("%d",&n);//存放需要判断的数n
    for(i=1;i<n;i++)//循环条件找出因子并累加
    {
        if(n%i==0)
            sum+=i;
    }
    if(n==sum)
        printf("%d 是完数\n",n);
    else
        printf("%d 不是完数\n",n);
    return 0;
}