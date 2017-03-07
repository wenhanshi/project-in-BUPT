//2. the Class of POINT & SQUARE
#include<iostream>
#include<math.h>
using namespace std;

class Point{
	public:
		//Point();
		Point(float x=0.0,float y=0.0);
		~Point()//INLINE
		{
			cout<<"The Point has been destroyed."<<endl;
		}
		float Getx()//INLINE
		{
			return X;
		}
		float Gety()//INLINE
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
		Rec();
		Rec(Point &lu,Point &rd);
		Rec(float lux,float luy,float rdx,float rdy);
		~Rec()
		{
			cout<<"The Rec has been destroyed."<<endl;
		}
		float square();
	private:
		Point LU,RD;
};

Rec::Rec()
{
	cout<<"Creating a rec by default..."<<endl;
	Point O(0.0,0.0);
	LU=O;
	RD=O;
}

Rec::Rec(Point &lu,Point &rd)
{
	cout<<"Creating a rec..."<<endl;
	LU=lu;
	RD=rd;
}

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
	back:
	cout<<"Input the two points: lu & rd:"<<endl;
	cout<<"lu x:"<<endl;
	cin>>lux;
	cout<<"lu y:"<<endl;
	cin>>luy;
	cout<<"rd x:"<<endl;
	cin>>rdx;
	cout<<"rd y:"<<endl;
	cin>>rdy;
	if(!( lux<rdx && luy>rdy ))
	{
		cout<<"Not match lu & rd."<<endl;
		goto back;
	}
	//four points to build(default overload "=" is needed)
	Point lu(lux,luy),rd(rdx,rdy);
	Rec rec1(lu,rd);
	cout<<"The square of rec1 is:"<<rec1.square()<<endl;
	//two points to build(opposite to the former situation)
	Rec rec2(lux,luy,rdx,rdy);
	cout<<"The square of rec2 is:"<<rec2.square()<<endl;
	return 0;
	
}
