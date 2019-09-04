#include <iostream>
using namespace std;
class base
{
	int arr[5] {1,2,3,4,5};
	public:
		base():arr{5,4,3,2,1}
                {};
        void show()
	{
	int i =0;
	for(;i<5; i++) {
		cout <<"value 1:"<<arr[i]<<endl;
	}
	}	
};

int main()
{
	base b ;
        b.show();
//	int *p = new (int) { 5};
//	cout <<"The value of p is"<<*p<<endl;
}
