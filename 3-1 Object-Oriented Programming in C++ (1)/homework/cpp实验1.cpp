//1. guess the value

#include<iostream>
#include<stdlib.h> 

using namespace std;

int main(void)
{
	int value=rand()%1000+1;
	int n;
	cout<<"Input the value 1-1000:\n";
	cin>>n;
	while(n!=value)
	{
		if(n>value) cout<<"Too high."<<endl;
		else cout<<"Too low.";
		cout<<"Input the value 1-1000:\n"<<endl;
		cin>>n;
	}
	cout<<"You're right."<<endl;
	return 0;
}
