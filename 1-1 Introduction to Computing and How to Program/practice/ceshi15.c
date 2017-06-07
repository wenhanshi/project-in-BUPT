#include<stdio.h>
int main(void)
{
	char i,j,k;
	for(i='X';i<='Z';i++)
	{
		for(j='X';j<='Z';j++)
		{
			if(i!=j)
			{
				for(k='X';k<='Z';k++)
				{
					if(k!=i&&k!=j)
					{
						if(i!='X'&&k!='X'&&k!='Z')
						{
							printf("A vs %c\nB vs %c\nC vs %c\n",i,j,k);
						}
					}
				}
			}
		}
	}
	return 0;
}
