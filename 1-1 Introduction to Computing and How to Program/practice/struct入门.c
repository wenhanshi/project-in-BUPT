#include<stdio.h>
int main(void)
{
	struct point
	{
		int x;
		int y;
		int z;
	};
	struct point pt={ 200,400,500};
	printf("%d %d %d",pt.x,pt.y,pt.z);
	return 0;
}
