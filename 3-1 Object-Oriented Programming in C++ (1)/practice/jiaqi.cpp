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
		int getMin(void)
		{
			return _min;
		}
		int getHour(void)
		{
			return _hour;
		}
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
		mini_clock(int min, int hour, unsigned int sat = 0);
		mini_clock(time & my_time , unsigned int sat = 0);
		mini_clock(mini_clock & );
		void showSat(void)
		{
			cout<<"Sat: "<<_sat<<endl;
		}
		void setSat(unsigned int Sat)
		{
			_sat=Sat;
		}
};

mini_clock::mini_clock(int min,int hour, unsigned int sat) : time ( min, hour )
{
	_sat=sat;
}
mini_clock::mini_clock(time & my_time , unsigned int sat) : time( my_time )
{
	_sat=sat;
}
mini_clock::mini_clock(mini_clock & mc) : time ( mc.getMin(), mc.getHour() )
{
	_sat=mc._sat;
}

int main(void)
{
	time t1;
	time t2(20,59);
	mini_clock mc1(1,3);
	mini_clock mc2(mc1);
	mc2.showSat();
	mc1.setSat(10);
	mc1.showSat();
	cout<<mc1<<endl;
	return 0;
}
