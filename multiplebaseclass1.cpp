#include<iostream>
using namespace std;
class b1
{
public:
	int i;
	int j;
	static int s;
	void function()
	{
	cout<<"THe base class function\n";
	}
};

int b1::s = 0;
class b2: public b1
{
public:
	int i;
	int j;
	void function()
	{
	cout<<"The base2 class function\n";
	}

};
class derived:  public b1, public b2
{
	public:
	int i;
	void function()
	{
	b2::j=0;
	s = 10;
	cout<<"The derived class function"<<s<<endl;
	}
};
int main()
{
	derived d1;
	d1.function();
	d1.b2::function();
//	d1.b1::function();
	d1.b2::j = 0;
//	d1.j = 0;
#if 0
	d1.b2::i =0;
	d1.b2::function();
	d1.b1::i =0;
	d1.b1::function();
	d1.b1::j = 0;
#endif
}
