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
	public:
	void function1(int a){
	cout<<"The function B class\n";
	}
};

class C: public B {
	public:
	void function1()
	{
	cout<<"The function C class\n";
	}
};

int main()
{
	class A a;
	class B b;
	b.A::function1();
	b.function1(2);
	class C c;
	c.function1();
	A *a1 = &b;
	a1->function1();
}
