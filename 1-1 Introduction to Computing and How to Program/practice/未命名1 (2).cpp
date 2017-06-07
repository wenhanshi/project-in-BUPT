#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    long long sum=0,n,i,store;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            sum+=i;
        }
        else
        {
            store=i;
            while(store%2==0)
            {
                store/=2;
            }
            sum+=store;
        }
    }
    printf("%lld",sum);
    system("pause");
    return 0;
}