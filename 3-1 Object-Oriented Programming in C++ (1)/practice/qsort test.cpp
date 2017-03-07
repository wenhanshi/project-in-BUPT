#include<algorithm> 
#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAX 500000
using namespace std;
int cmp(const void*a,const void*b)
{
	return -*(int*)b+*(int*)a;
} 
int main(void)
{
	long a[MAX];
	srand(time(NULL));
	int t,end;
	for(int i=0;i<=MAX-1;i++)
	{
		a[i]=rand()%10000+1;
	}
	t=clock();
	qsort(a,MAX,sizeof(long),cmp);
	qsort(a,MAX,sizeof(long),cmp);
	qsort(a,MAX,sizeof(long),cmp);
	qsort(a,MAX,sizeof(long),cmp);
	qsort(a,MAX,sizeof(long),cmp);
	end=clock();
	cout<<end-t<<endl;
	return 0;
}
