#include<iostream>
using namespace std;

class base
{
char *buf;
int cap;
public:
base(int c, const char *str):cap(c),buf(new char[cap]) {}
~base() {};


};
int main()
{
const char *str="he";
base b1(2,str);

}
