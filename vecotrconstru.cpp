#include<iostream>
#include<vector>
using namespace std;
class base
{
	int a,b;
	public:
//	base(){};
	base(int x, int y):a(x),b(y) {};
        ~base() {};
};

int main()
{
	vector<base> b1[1];
//	b1.push_back(base(2,3));


}
