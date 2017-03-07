//11.copy a txt with the line number

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(void)
{
	char name_buf[255];
	char buffer[255];
	back:
	cout<<"Input the sourcefile (default:sourcefile.txt)"<<endl;
	gets(name_buf);
	ifstream file(name_buf);
	ofstream dest("destfile.txt"); 
	if(!file.is_open() || !dest.is_open())
	{
		cout<<"ERROR:File can't be opened.\n";
		goto back;
		return 1;
	}
	else
	{
		int count=0;
		while(!file.eof())
		{
			file.getline(&buffer[3],255);
			buffer[2]=' ';
			buffer[1]=count%10+'0';
			buffer[0]=count/10+'0';
			count++;
			dest<<buffer<<endl;
		}
		cout<<"The copy finished."<<endl;
	}
	file.close();
	dest.close();
	return 0;
}
