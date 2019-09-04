#include <iostream>
using namespace std;

class base{
	//const int a;
	int a;
	int *b;
	public: 
	base(int x ): a(x) {
	b = new int;
	*b = x; 
	}
	//base( const base &x, int j = 4) {
	//base( volatile base &x, int j = 4) {
	//base( volatile base &x, int j = 4) {
	base( const volatile base &x, int j = 4) {
	b = new int;
	*b = x.a;
	a = *b;
	cout<<"The copy constructor called"<<j<<endl;
	}

        base & operator=(const base &x){
        *(this->b) = *(x.b);
	a = x.a;
	return *this;
	}  	
        ~base() {
	delete b;
	}
	void set_data(const int x)
	{

	a=x;
	}
	void get_data()
	{
	cout<<"The value is:"<<a<<endl;
	
	}
};

class state
{
	static const int i = sizeof(int) *sizeof(char);
        const int j;
	int &arg;  
        public:
	state (int &h):arg(h),j(7) {
//	state (int &h) {
	arg = h;
//	j = 7;
	}
	void print()
	{
	cout<<"The state value:"<<i<<arg<<j;
	}
};


int main()
{
        base b(2);
	b.get_data();
        base b1(8);
//	b1.set_data(4);
	b1.get_data();
        base b2 = b1; 
	b2.get_data();
	b2 = b;
	b2.get_data();
	b2 = b;
	int x = 8;
	state s(x);
	s.print();
	return 0;

}
