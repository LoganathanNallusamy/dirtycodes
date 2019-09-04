#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Base {
private:
	int a,b;
public:
	virtual void func(int a) {

	cout<<"Base class function \n";
	}

};

class Derived: public Base {
private:
	int x,y;
public:
	virtual void func(float a)  {
	cout<<"Derived class function \n";
	}
};

int main()
{
	Base *der = new Derived;
	der->func(1.2);
	return 0;	
}
