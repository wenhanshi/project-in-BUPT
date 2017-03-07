//7. Derived Class--Shape

#include<iostream>
using namespace std;
//CLASS SHAPE
class Shape{
	private:
		int _x,_y;
	public:
		Shape();
		Shape(int x,int y);
		~Shape();
		void Area(){};//doesnt matter,can be virtured later
		void getXY(int &x,int &y);
		void setXY(int x,int y)
		{
			_x=x;
			_y=y;
		}
};

Shape::Shape()
{
	cout<<"Creating a shape by default..."<<endl;
	_x=0;
	_y=0;
}
Shape::Shape(int x,int y)
{
	cout<<"Creating a shape by some parameters..."<<endl;
	_x=x;
	_y=y;
}
Shape::~Shape()
{
	cout<<"Destroying a shape..."<<endl;
}
void Shape::getXY(int &x,int &y)
{
	x=_x;
	y=_y;
}
//END SHAPE

//CLASS CIRCLE FROM SHPAE
class Circle: public Shape{
	private:
		unsigned int R;
	public:
		Circle();
		Circle(int x,int y,unsigned int r);
		~Circle();
		float Area(); 
};


Circle::Circle()
{
	cout<<"Creating a Circle by default..."<<endl;
	R=0.0;
}

Circle::Circle(int x,int y,unsigned int r):Shape(x,y)
{
	cout<<"Creating a Circle by some parameters..."<<endl;
	R=r;
}

Circle::~Circle()
{
	cout<<"Destroying a Circle..."<<endl;
}

float Circle::Area()
{
	return 3.14*R*R;
}
//END CIRCLE

//CLASS RECTANGLE FROM SHAPE
class Rectangle: public Shape{
	private:
		unsigned int L,W;
	public:
		Rectangle();
		Rectangle(int x,int y,unsigned int l,unsigned int w);
		~Rectangle();
		void setL(unsigned int l)
		{
			L=l;
		}
		void setW(unsigned int w)
		{
			W=w;
		}
		int Area();
};

Rectangle::Rectangle()
{
	cout<<"Creating a Rectangle by default..."<<endl;
	L=0;
	W=0;
}

Rectangle::Rectangle(int x,int y,unsigned int l,unsigned int w):Shape(x,y)
{
	cout<<"Creating a Rectangle by some parameters..."<<endl;
	L=l;
	W=w;
}

Rectangle::~Rectangle()
{
	cout<<"Destroying a Rectangle..."<<endl;
}

int Rectangle::Area()
{
	return W*L;
}
//END RECTANGLE

//CLASS SQUARE FROM RECTANGLE FROM SHAPE
class Square: public Rectangle{
	public:
		Square();
		Square(int x,int y,unsigned int side);
		~Square();
		int Area();
};

Square::Square()//with set
{
	cout<<"Creating a Square by default..."<<endl;
	setW(0);
	setL(0);
	setXY(0,0);
}

Square::Square(int x,int y,unsigned int side):Rectangle(x,y,side,side)
{
	cout<<"Creating a Square by some parameters..."<<endl;
}

Square::~Square()
{
	cout<<"Destroying a Square..."<<endl;
}

int Square::Area()
{
	return Rectangle::Area();
}
//END SQUARE

int main(void)
{
	Circle C1(1,1,10);
	cout<<"The Area of the C1 is:"<<C1.Area()<<endl;
	Rectangle R1(1,1,2,3);
	cout<<"The Area of the R1 is:"<<R1.Area()<<endl;
	Square S1(0,0,9);
	cout<<"The Area of the S1 is:"<<S1.Area()<<endl;
	 
	return 0;
}
