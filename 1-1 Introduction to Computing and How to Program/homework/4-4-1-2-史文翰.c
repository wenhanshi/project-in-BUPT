#include<stdio.h>
int main(void)
{
	char a;
	short b;
	int c;
	long d;
	long long e;
	float f;
	double g;
	
	printf("Please input seven parts:\n");
	scanf("%c%hd%d%ld%lld%f%lf",&a,&b,&c,&d,&e,&f,&g);
	printf("The result is:\n");
	printf("The'char'variable is %c,it takes %d byte\n",a,sizeof(a));
	printf("The'short'variable is %hd,it takes %d bytes\n",b,sizeof(b));
	printf("The'int'variable is %d,it takes %d bytes\n",c,sizeof(c));
	printf("The'long'variable is %ld,it takes %d bytes\n",d,sizeof(d));
	printf("The'long long'variable is %lld,it takes %d bytes\n",e,sizeof(e));
	printf("The'float'variable is %f,it takes %d bytes\n",f,sizeof(f));
	printf("The'double'variable is %lf,it takes %d bytes\n",g,sizeof(g));
	
	return 0;
}
