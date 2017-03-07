//2. the Class of POINT & SQUARE
#include<iostream>
#include<math.h>
using namespace std;

class Point{
	public:
		Point(float x=0.0,float y=0.0);
		~Point()
		{
			cout<<"The Point has been destroyed."<<endl;
		}
		float Getx()
		{
			return X;
		}
		float Gety()
		{
			return Y;
		}
		float dis(Point &P);
	private:
		float X,Y;
};

Point::Point(float x,float y)
{
	cout<<"Creating a Point..."<<endl;
	X=x;
	Y=y;
}

 float Point::dis(Point &P)
{
	return  sqrt((X-P.X)*(X-P.X)+(Y-P.Y)*(Y-P.Y));
}

class Rec{
	public:
		Rec(float,float,float,float);
		~Rec()
		{
			cout<<"The Rec has been destroyed."<<endl;
		}
		float square();
	private:
		Point LU,RD;
};

Rec::Rec(float lux,float luy,float rdx,float rdy):LU(lux,luy),RD(rdx,rdy)
{
	cout<<"Creating a rec..."<<endl;
}

float Rec::square()
{
	return fabs( ( LU.Getx()-RD.Getx() ) * ( LU.Gety()-RD.Gety() ) );
}

int main(void)
{
	float lux,luy,rdx,rdy;
	cout<<"Input the two points: lu & rd:"<<endl;
	cout<<"lu x:"<<endl;
	cin>>lux;
	cout<<"lu y:"<<endl;
	cin>>luy;
	cout<<"rd x:"<<endl;
	cin>>rdx;
	cout<<"rd y:"<<endl;
	cin>>rdy;
	
	Rec rec(lux,luy,rdx,rdy);
	cout<<"The square of rec is:"<<rec.square()<<endl;
	return 0;
	
}
