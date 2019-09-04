#include<iostream>
#include<cstring>
using namespace std;
class string2
{
	int a,b;
	char arr[10];
	public:
	string2(int x,int y): a(x),b(y) {};
	string2(int x)
	{
	a=x;
	}
	explicit string2(char *str)
	{
	strcpy(arr,str);
	}
	void print()
	{
	  cout<<"The value is"<<a<<endl;
	}

};
int main()
{
	string2 s(1,2);
        string2 s1= 9 ;;// string(9)
	string s3;
	s3="hello";	
        s.print();
        s1.print();
	
}
