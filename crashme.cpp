#include <iostream>
#include <cstring>
using namespace std;
class sample {
	public:
        sample () {
            data = new char[10];
            std::strcpy(data, "noName");
        }
        sample(const char *str){
              data = new char[std::strlen(str) + 1]; 
              std::strcpy(data,str);
       }
       sample(const sample &rhs){
           data = new char[10];
           std::strcpy(data, rhs.data);
       }
       sample & operator=( const sample &r){
            std::strcpy(data, r.data);
            //return *this;
       }
       ~sample()
       {
          delete []data;
       }
       void showData() const
       {
 	 cout<<"data ="<<data<<endl;
       }
       private:
        char *data;
      
};

void crashme()

{
    sample sa("one"), sb;
    sample temp(sa);
    sa.showData();
    sb.showData();    
    temp.showData();
    sb = temp;
    sb.showData();
 
}

int main()
{
   crashme();
}
