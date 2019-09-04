#include <iostream>
using namespace std;

class base {

public:
  virtual   void serviceA() { cout << "Basic service\n"; }
     base() { cout <<__PRETTY_FUNCTION__ <<endl;}
     ~base() { cout <<__PRETTY_FUNCTION__ <<endl; }
};

class better: public base {

public:
     void serviceA() { cout << "better  service\n"; }
      better() { cout<< __PRETTY_FUNCTION__  <<endl;}
      ~better() { cout << __PRETTY_FUNCTION__ <<endl; }

};

class best: public better {
 public:
     void serviceA() { cout << "best  service\n"; }
      best() { cout<< __PRETTY_FUNCTION__ <<endl;}
      ~best() { cout << __PRETTY_FUNCTION__ <<endl; }
};

void interfaceA(base &b)
{
   b.serviceA();
}

void interfaceb(base b)
{
   b.serviceA();
}

void interfacec(base *bp)
{
   bp->serviceA();
}


int main()
{
#if 0
	base    obasic;
 	better  obetter;
        best    obest;
        interfaceA(obasic);
        interfaceA(obetter);
        interfaceA(obest);
#endif
        base *bp ;

        int choice = 1;
        while(1) {
        cin>>choice;
          switch(choice) {
          case 1:
                  bp = new base();
                  interfacec(bp);
                  delete bp;
                  break;
          case 2:
                  bp = new better();
                  interfacec(bp);
                  delete bp;
                  break;
          case 3:
                  bp = new best();
                  interfacec(bp);
                  delete bp;
                  break;
         }      

        } 
}
