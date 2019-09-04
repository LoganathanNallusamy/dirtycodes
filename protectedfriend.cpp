#include<iostream>
using namespace std;
class base
{
protected:
	int i;
};

class derived: public base
{
public:

friend void f(base *b, derived *d){
    cout<<"the friend function called\n";
//    b->i = 3;
    d->i = 9;
}
void g(base *bp)
{
  i =2;	
//  bp->i = 7;
  cout<<"The value of i is"<<base::i<<endl;
}

};

int main()
{
derived d1;
d1.g(&d1);
base b;
f(&b,&d1);
}
