#include<iostream>
using namespace std;

class B {
	public:
	B()
	{
	cout<<"base class const B\n";
	}

};

class B1 {
	public:
	B1()
	{
	cout<<"base class const B1\n";
	}

};

class D
{
	public:
	B1 a1;
	B a;
	D()
	{
	cout<<"Dervied Class cons D\n";
	}
};
int main()
{
     D d;

}
