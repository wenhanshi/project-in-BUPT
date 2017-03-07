#include<iostream>
#include<cstring>
using namespace std;
class time{
	private:
		int _min;
		int _hour;
		static int num_clock;
	public:
		time();
		explicit time(double test);
		time(int min,int hour);
		time(time &);
		time operator +(const time &another_time) const;
		void showTime(void);
		//friend void test(time& test_time);
		int get_num_clock(void)
		{
			return num_clock;
		}
		friend ostream & operator <<(ostream &os, time &time_need_to_show);
};

int time::num_clock=0;
time::time(time &other_time)
{
	_min=other_time._min;
	_hour=other_time._hour;
}
time::time()
{
	_min=_hour=0;
	num_clock++;
}
time::time(int min,int hour)
{
	_min=min;
	_hour=hour;
	num_clock++;
}
time::time(double test)
{
	_hour = _min = test;
}
time time::operator +(const time &another_time) const
{
	time blank;
	blank._min=(_min+another_time._min)% 60 ;
	blank._hour=_hour+another_time._hour+(_min+another_time._min) / 60 ;
	return blank;
}
void time::showTime()
{
	cout<<_hour<<":"<<_min<<endl;
}
ostream & operator <<(ostream &os, time &time_need_to_show)
{
	os<<time_need_to_show._hour<<":"<<time_need_to_show._min;
	return os;
}

class mini_clock : public time
{
	private:
		unsigned int _sat;
	public:
		mini_clock(int min, int hour, unsigned sat=0);
		mini_clock(time & my_time , unsigned sat=0);
		mini_clock(mini_clock & );
		void showSat(void);
}
class badString{
	private:
		char *str;
		int len;
	public:
		badString();
		badString(const char *other_str);
		~badString();
		char & operator [](int p);
		badString & operator =(badString & );
		void test(time& test_time);
};
/*void badString::test(time& test_time)
{
	len=test_time._min;
}*/
badString::badString()
{
	str=new char[1];
	str[0]='\0';
	len=0;
}
badString::badString(const char *other_str)
{
	len=strlen(other_str);
	str=new char[len+1];
	strcpy(str,other_str);
}
badString::~badString()
{
	delete [] str;
}
char & badString::operator [](int p)
{
	return str[p];
}
badString & badString::operator =(badString &other_string )
{
	if( this == & other_string)
		return *this;
	delete [] str;
	str = new char [other_string.len];
	strcpy( str, other_string.str);
	return *this;
}
int main(void)
{
	time t1(2,30),t2(4,45),t3(3,3),temp;
	//time test;
	//test=10; //cant because of explicit
	//test=(time)10;// ok 
	//test=time(10);// ok another way
	temp=t1+t2+t3;
	time isadd=temp;//didnt add 1 to num_clock because of default c.c.
	cout<<temp<<" hehehe"<<endl;
	cout<<t1.get_num_clock()<<" "<<t2.get_num_clock()<<endl;
	//cout<<test;
	badString *ptrS = new badString("woshishabi") ;
	badString str1="wocao";
	badString str2;
	str2=str1;
	cout<<str1[2]<<endl;
	cout<<(*ptrS)[3]<<endl;
	cout<<str2[2]<<endl;
	return 0;
}
