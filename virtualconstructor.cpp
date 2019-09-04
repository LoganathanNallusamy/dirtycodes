#include<iostream>
using namespace std;

class base
{
	public:
	base()
	{
	cout<<"base class constru\n";
	}
	virtual base *construct() {
	return new base;
	}
	void function1()
	{
	cout<<"Base class function\n";
	}
	virtual ~base()
	{
	cout<<"base class destructor\n";
	}

};

class derived: public base
{
	public:
	 derived *construct() {
	cout<<"Derived class constur member functon\n";
	return new derived;
	}
	void function2()
	{
	cout<<"Derived class function\n";
	}
	derived()
	{
	cout<<"Derived class constr\n";
	}
	~derived()
	{
	cout<<"Derived class destr\n";
	}
};

int main()
{
	base *b = new derived();
	cout<<"base class construis done for baseptr\n";
	base *d1 = b->construct();
	delete b;
	delete d1;
}
