#include <iostream>
using namespace std;
class  device
{
//  char a;
 int arr[0];
};

struct s1
{
//  int arr[0];
};

int main()
{
 device a;
 device b;
 cout<<"the size of class: "<<sizeof(class device)<<"size of object:"<<sizeof(a)<<"Address of obj"<<&a<<endl;
 cout<<"size of object b:"<<sizeof(b)<<"Address of obj"<<&b<<endl;
 cout<<"the size of struct: "<<sizeof(struct s1)<<endl;
 return 0;

}
