#include<iostream>
#include<string>
#include<vector>

using namespace std;

class A
{
	public:
	A(int ii, int jj) {
	int  i1 = ii;
	int  j1 = jj;
	cout<<"Constructor is called\n";
	}
	A(const A &a) {
	cout<<"Copy constructor \n";
	}
#if 0
	A(const A &&a) {
	cout<<"Move constructor \n";
	}
#endif
	~A()
	{
	cout<<"Destructor is called\n";
	}


};
int main()
{
	vector<A> el;
//	el.push_back(A(1,2));
//	cout<<"End of push\n";
	el.emplace_back(1,2);
	cout<<"End of emplace\n";
	return 0;
}
