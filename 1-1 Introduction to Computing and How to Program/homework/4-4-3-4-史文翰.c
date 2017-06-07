#include<stdio.h>
int main(void)
{
	int count=1;
	char i,j,k,l;
	printf("The result of ballot is:\n");
	for(i='W';i<='Z';i++)
	{
		for(j='W';j<='Z';j++)
		{
			if(i!=j)
			{
				for(k='W';k<='Z';k++)
				{
					if(i!=k&&j!=k)
					{
						for(l='W';l<='Z';l++)
						{
							if(l!=i&&l!=j&&l!=k)
							{
								if(i!='X'&&k!='X'&&k!='Z'&&l!='W')
								{
									printf("Group %d:\nA VS %c\nB VS %c\nC VS %c\nD VS %c\n\n",count,i,j,k,l);
									count++;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("There are %d ways to assign the players.",count);
}
