#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int a,b,c,ans=1;
    scanf("%d%d%d",&a,&b,&c);
    while(b>0)
    {
        if(b%2==1)
        {
            ans=(ans*a)%c;
        }
        b/=2;
        a=(a*a)%c;
    }
    printf("%d",ans);
    system("pause");
    return 0;
}