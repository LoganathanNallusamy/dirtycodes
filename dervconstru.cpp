#include<iostream>
using namespace std;
class B1
{
	int b;
 public:
	B1()
	{
	cout<<"Default B1 constructors\n";		
	}
	B1(int a)
	{
	cout<<"Parameterised B1 const\n";
	b =a;
	}
	~B1()
	{
	cout<<"B1 destructor\n";
	}

};

class B2
{
	int b2;
	B2()
	{
	cout<<"Default B2 constructors\n";		
	}
 protected:
#if 0
	B2()
	{
	cout<<"Default B2 constructors\n";		
	}
#endif
	B2(int a)
	{
	cout<<"Parameterised B2 const\n";
	b2 =a;
	}
	~B2()
	{
	cout<<"B2 destructor\n";
	}

};

class Der: public B1, B2
{
	int i,j;
	public:
	//Der(int x, int y):i(x),B1(x),B2(x) {
	Der(int x, int y):i(x),B1(x) {
	    j =y;
	    cout<<"Derived Class constructor\n";
	}
	~Der()
	{
	    cout<<"Dervived class destructor\n";	
	}

};

int main()
{
//	Der d1(2,3);

}
