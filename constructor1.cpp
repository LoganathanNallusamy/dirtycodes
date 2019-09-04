#include <iostream>
using namespace std;
class base
{
	int k;
	public:
//virtual	base() { cout<<"Base class cons\n";}
//static	base() { cout<<"Base class cons\n";}
	base(int 1) { cout<<"Base class cons\n";}
	virtual ~base() {cout<<"base class destru\n";}
};
int main()
{
   base b(2);

}
