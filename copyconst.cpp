#include<iostream>
using namespace std;
class base
{
 public:
	base() {
	cout<<"Base clss cons\n";
	}
	base(base &a){
	cout<<"Base class copy constr\n";
	}

};

class derived: public base
{
public:
	derived() { cout<<"Derived class constr\n";}
	derived(const derived &b) {
	
	cout<<"Derved class copy const\n";
	}

};

int main()
{
	base b;
	derived d;
	derived d1 = b;

}
