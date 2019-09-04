#include<iostream>
using namespace std;
class B0
{
public:
	virtual void function()
	{
 	cout<<"B0 function class\n";
	}
};


//class B1: virtual public B0
class B1:  public B0
{
public:
	virtual void function() {
	cout<<"B1 function class\n";
	}	
        void functionB1()
	{
	cout<<"FUNCTION SPECIFIC to B1\n";
	}
};

//class B2:virtual public B0
class B2: public B0
{
public:
	virtual void function()
	{
	cout<<"B2 function class \n";
	}
        void functionB2()
	{
	cout<<"FUNCTION SPECIFIC to B2\n";
	}

};

class der: public B1, public B2
{
public:
      void function()
      {
	cout<<"Derived class function\n";
      }
        void functionDer()
	{
	cout<<"FUNCTION SPECIFIC to Der\n";
	}

};
int main()
{
  der d;
  d.function();
  d.B1::function();
  d.B2::function();
  cout<<"The upcast function\n";
  B1 *b1 = &d;
  b1->function();
  b1 = dynamic_cast<B1 *>(&d);
  if (b1) {		
	  b1->function();
	  //b1->functionDer();
  }
  cout<<"The derived class ptr:"<<&d<<"B1 dynamic cast ptr:"<<b1<<endl;
  cout<<"The derived class ptr:"<<&d<<"B1 dynamic cast ptr:"<<b1<<endl;
  cout<<"The derived class ptr:"<<&d<<"B1 dynamic cast ptr:"<<b1<<endl;
  B2 *b2 = dynamic_cast<B2 *>(&d);
  if (b2) {		
	  b2->function();
  }
  cout<<"The derived class ptr:"<<&d<<"B2 dynamic cast ptr:"<<b2<<endl;
  b2 = dynamic_cast<B2 *>(&d);
  cout<<"The derived class ptr:"<<&d<<"B2 dynamic cast ptr:"<<b2<<endl;

  B1 *b11 = new der;
  b11->function();
  B2 *b12 = dynamic_cast<B2 *>(b11);
  if (b12)
  {
     cout<<"Cross cast is successful from B1 to B2\n";
     b12->function();
  }
  cout<<"Downcast in diamond shape\n";
  B0 *b0 = new der;
  b0->function();
    
  B1 *bb1 = dynamic_cast<B1 *>(b0);
  if (bb1) {
      cout<<"Downcast is successful.\n";
      bb1->function();  	
  }
}

