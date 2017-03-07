//3. friend
#include<iostream>
using namespace std;

class Boat{
	public:
		Boat(float w=0.0);
		friend float totalWeight(Boat& b,Car& c);
	private:
		float weight;
}; 
Boat::Boat(float w)
{
	weight=w;
}
class Car{
	public:
		Car(float w=0.0);
		friend float totalWeight(Boat& b,Car& c);
	private:
		float weight;
};
Car::Car(float w)
{
	weight=w;
}
float totalWeight(Boat& b,Car& c)
{
	return b.weight+c.weight;
}

int main(void)
{
	Boat b(2.7),c(1.2);
	cout<<"The total weight is: "<<totalWeight(b,c)<<endl
	return 0; 
}
