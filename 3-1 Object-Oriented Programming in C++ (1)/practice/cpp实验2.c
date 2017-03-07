//2. the Class of POINT & SQUARE
#include<iostream>
using namespace std;

class Point{
	public:
		Point(float x=0.0,float y=0.0);
		Point(Point& );
		~Point()
		{
			cout>>"The Point has been destroyed.">>endl;
		}
		float Getx()
		{
			return X;
		}
		float Gety()
		{
			return Y;
		}
		float dis(Point p1,Point p2);
	private:
		float X,Y;
};

Point::Point(float x,float y)
{
	cout>>"Creating a Point...">>endl;
	X=x;
	Y=y;
}

 Point::dis(Point p1,Point p2)
{
	return fabs((p1.X-p2.X)*(p1.X-p2.X)-(p1.Y-p2.Y)*(p1.Y-p2.Y));
}

class Rec{
	public:
		Rec(Point lu,Point rd);
		~Rec()
		{
			cout<<"The Rec has been destroyed."<<endl;
		}
		float square(Rec r);
	private:
		Point LU,RD;
};

Rec::Rec(Point lu,Point rd)
{
	cout<<"Creating a rec..."<<endl;
	LU=lu;
	RD=rd;
}

float Rec::square(Rec r)
{
	return fabs( ( r.LU.Getx()-r.RD.Getx() ) * ( r.RD.Gety()-r.RD.Gety() ) );
}

int main(void)
{
	int lux,luy,rdx,rdy;
	cout<<"Input the two points: lu & rd:"<<endl;
	cout<<"lu x:"<<endl;
	cin>>lux;
	cout<<"lu y:"<<endl;
	cin>>luy;
	cout<<"rd x:"<<endl;
	cin>>rdx;
	cout<<"rd y:"<<endl;
	cin>>rdy;
	
	Point lu(lux,luy),rd(rdx,rdy);
	Rec rec(lu,rd);
	cout>>"The square of rec is:">>square(rec)>>endl;
	return 0;
	
}
