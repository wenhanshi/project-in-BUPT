#include<iostream>
using namespace std;
namespace LAOSHI{
	int h=2;
	int arr[100];
}

template <typename any>
void swapt(any &a,any &b)
{
	any temp;
	temp=a;
	a=b;
	b=temp;
}
class some{
	private:
		int _a;
		int _b;
	public:
		some(int a,int b);
		void show() const;
		const some& comp(const some& );
};

const some& some::comp(const some& other)
{
	if(_a>other._a)
		return other;
	return *this;
}


some::some(int a=1,int b=1)
{
	_a=a;
	_b=b;
}

void some::show() const
{
	cout<<"show:"<<_a<<" "<<_b<<endl;
}

int main(void)
{
	using namespace LAOSHI;
	some orb;
	some orb1(3);
	some blank;
	blank=orb.comp(orb1);
	blank.show();
	orb.show();
	cout<<h<<endl;
	arr[0]=0;
	double a=1.0,b=2.7;
	cout<<a<<","<<b<<endl;
	swapt(a,b);
	cout<<a<<","<<b<<endl;
	return 0;
 } 
