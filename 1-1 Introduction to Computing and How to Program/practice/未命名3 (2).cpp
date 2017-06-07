#include<stdio.h>
#include<stdlib.h>
long a,b,c;
int powerMod(long a,long b,int c)
{
    int ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=(ans*a)%c;
        }
        b/=2;
        a=(a*a)%c;
    }
    return ans;
}
int main(void)
{
    long sum=0,result;
    int k,i;
    scanf("%ld%ld%d",&a,&b,&k);
    for(i=a;i<=b;i++)
    {
        sum+=powerMod(i,i,k);
    }
    printf("%ld",sum%k);
    system("pause");
    return 0;
}