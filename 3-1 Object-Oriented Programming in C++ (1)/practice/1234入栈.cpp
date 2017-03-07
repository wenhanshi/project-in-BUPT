#include<stdio.h>



int main(void)
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			for(int k=1;k<=4;k++)
			{
				for(int l=1;l<=4;l++)
				{
					if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
					{
						if(! ( (i>j&&j<k&&i>k) || (j>k&&k<l&&j>l) || (i==4&&(j==1||j==2))) )
						{
							printf("%d%d%d%d\n",i,j,k,l);
						}
					}
				}
			}
		}
	}
	return 0;
}

