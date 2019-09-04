#include <iostream>
using namespace std;
namespace A {
	struct X {
 	int a;
	};
	void g(X a){ cout <<"calling namespace A::g()"; }
}

void g(A::X a)
{
  cout<<"Calling globalspace g function";
}

int main()
{
  A::X x1;
  A::g(x1);  
  return 1;
}
