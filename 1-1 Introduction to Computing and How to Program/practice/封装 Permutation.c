#include<stdio.h>
 

int n;
int a[100 + 1];
int num[100 + 1];

void Permutation(int k)
{
	if (k == n + 1)	
	{
		int i;
		for (i = 1; i < k; i ++)
			printf("%d ", a[i]);
		printf("\n");
		return ;
	}
	int i;
	for (i = 1;i <= n; i ++)
		if(num[i] == 0)
		{
			num[i] = 1;
			a[k] = i;
			Permutation(k + 1);
			num[i] = 0;
		}
	return ;
}

int main(void)
{
	scanf("%d", &n);
	Permutation(1);
	return 0;
}


