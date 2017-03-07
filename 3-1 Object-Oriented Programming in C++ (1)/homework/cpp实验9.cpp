//9.overload ++ & --

#include<iostream>
using namespace std;

class Point{
	private:
		int X,Y;
	public:
		Point();
		Point(Point&);
		Point(int x,int y);
		~Point();
		void getXY(int &x,int &y){ X=x; Y=y; }; 
		Point& operator ++(void);
		Point& operator --(void);
		Point& operator ++(int);
		Point& operator --(int);
		void print();
};
Point::Point()
{
	X=0;
	Y=0;
}
Point::Point(Point &P)
{
	X=P.X;
	Y=P.Y;
}
Point::Point(int x,int y)
{
	X=x;
	Y=y;
}
Point::~Point()
{
	cout<<"DECONSTRUCTING..."<<endl;
}
Point& Point::operator ++(void)
{
	X++;
	Y++;
	return *this;
}

Point& Point::operator --(void)
{
	X--;
	Y--;
	return *this;
}
Point& Point::operator ++(int)
{
	X++;
	Y++;
	return *this;
}

Point& Point::operator --(int)
{
	X--;
	Y--;
	return *this;
}


void Point::print()
{
	cout<<"X="<<X<<","<<"Y="<<Y<<endl;
}

int main(void)
{
	Point A(0,0);
	A.print();
	++A;
	A.print();
	--A;
	A.print();
	A++;
	A.print();
	A--;
	A.print();
	return 0;
}
