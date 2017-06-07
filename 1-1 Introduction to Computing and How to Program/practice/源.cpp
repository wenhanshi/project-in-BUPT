#include<stdio.h>
#include<stdlib.h>
int main()
{
	int reduc(int x, int y);
	int n, m;
	long int product = 1, sum = 0;
	scanf("%d", &n);
	int *a;
	a = (int*)malloc(sizeof(int)*n);
	for (int i = 3; i <= 2 * n + 1; i += 2)
	{
		product *= i;
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = product*(2 * i - 1) / (2 * i + 1);
		sum += a[i];
	}
	while ((m=reduc(sum, product)) != 1){
		sum = sum / m;
		product = product / m;
	}
	printf("%ld/%ld", sum, product);
}
int reduc(int x, int y)
{
	int i;
	for ( i = 1; i <= x; i++)
	{
		if (x%i == 0 && y%i == 0) break;
	}
	return i;
}
