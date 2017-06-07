#include<stdio.h>
#include<ctype.h>

#define NKEY sizeof(akey)/sizeof(akey[0])
#define LOOP for(int i=0;i<=NKEY-1;i++)

struct key{
	char alpha;
	int num;
} akey[]={
	'a',0,
	'b',0,
	'c',0,
	'd',0,
	'e',0,
};

int main(void)
{
	char c;
	int sum;
	while((c=getchar())!=EOF)
	{
		if(!isspace(c))
		{
			LOOP
			{
				if(akey[i].alpha==c)
				{
					akey[i].num++;
				}
			}
		}
	}
	LOOP
	{
		sum+=akey[i].num;
	}
	LOOP
	{
		printf("\nword:%c %.2lf%%\n",akey[i].alpha,((double)akey[i].num/sum)*100);
	}
	return 0;
}
