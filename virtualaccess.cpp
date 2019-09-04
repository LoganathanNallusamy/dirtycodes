#include<iostream>
using namespace std;
class A {
	public:
	virtual void function1()
	{
	cout<<"The function A class\n";
	}

};

class B :public A {
	void function1(){
	cout<<"The function B class\n";
	}
};

int main()
{
	class A a;
	class B b;
	A *a1 = &b;
	a1->A::function1();
}
