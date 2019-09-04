#include<iostream>
#include<string>
using namespace std;
int main()
{
	int num = 100;
	string str = to_string(num);
	cout<<"The number in integer is "<<num<<" string form: "<<str<<" size is "<<str.size()<<endl;

	cout<<"String is ";
	for (int i =0; i < str.size(); ++i) {
		cout<<str[i]-'0'<<" ";	

	}
	cout<<endl;
	return 0;
}
