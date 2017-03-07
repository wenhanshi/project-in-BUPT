
#include<iostream>
using namespace std;

void init(int (&a)[1])
{
	a[0]=100;
}
int main(void)
{
	int a[1]={0};
	cout<<a[0];
	return 0;
}
