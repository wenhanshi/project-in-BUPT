//10.file ofstream

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(void)
{
	//整数、无符号整型、长整型、浮点型、字符串、……
	int i=0;
	unsigned int ui=2;
	long l=5435345;
	float f=32.02712;
	char s[255]="HELLO WORLD!";
	
	int test_int=225;
	
	ofstream file("out.txt",ios::out|ios::in);
	if(file.is_open())
	{
		file<<"int:"<<i<<endl;
		file<<"unsigned int:"<<ui<<endl;
		file<<"long:"<<l<<endl;
		file<<"float:"<<f<<endl;
		file<<"string:"<<s<<endl;
		file<<endl;
		
		file<<"十进制输出："<<dec<<test_int<<endl;
		file<<"八进制输出："<<oct<<test_int<<endl;
		file<<"十六进制输出："<<hex<<test_int<<endl;
		
		// by func setprecision 
		file<<"By setprecision: "<<endl;
		for(int i=1;i<=7;i++)//2.0 will be displayed by 2 & SSWR 
		{
			file<<setprecision(i)<<f<<endl;
		}
		
		// by member func precision
		file<<"By member func precision: "<<endl;
		for(int i=1;i<=7;i++)
		{
			file.precision(i);
			file<<f<<endl;
		}
		
		file<<"Some other member funcs: "<<endl;
		file<<"科学计数法："<<setiosflags(ios::scientific)<<setprecision(8)<<f<<endl;
		file.setf(ios::fixed);
		file.precision(4);
		for(int i=1;i<=10;i++)
		{
			file<<setfill('*')<<setw(i)<<f<<endl;
		}
		file.close();
	}
	return 0;
}
