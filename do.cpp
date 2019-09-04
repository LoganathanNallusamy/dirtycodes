#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a = 100000;
	int b = 100001;
	double val  = 0.0;
 	val=( a+b)/2;
	cout<<"Value is "<<val<<endl;
 	val=( a+b)/2.0;
	
	cout<<"Value is "<<val<<endl;
 	val=( (double)a+(double)b)/2.0;
	cout.precision(7);
	cout<<"Value is "<<val<<endl;
	return 0;
}
