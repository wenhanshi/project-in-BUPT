#include<stdio.h>
int main(void)
{
		int i,j=0,n,a,b,p1,p2,p3,p4;
	scanf("%d%d",i,n);
	p1=i/1000;
		p2=i%1000/100;
		p3=i%100/10;
		p4=i%10;
		if(p1>=1&&p1<=n&&p2>=1&&p2<=n&&p3>=1&&p3<=n&&p4>=1&&p4<=n&&p1!=p2&&p1!=p3&&p1!=p4&&p2!=p3&&p2!=p4&&p3!=p4)
		{
			printf("%d\t",i);
		}
		return 0;
}
