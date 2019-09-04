#include <iostream>
using namespace std;

class date
{
   public:
	date()= delete;
  	date(int a, std::string s, int c) = delete;
  	//date(int a, std::string s, int c){};
  private:
	int day;
	char month[4];
	int year;
};

class device
{
   public:
	device() = default;
	device(int) {};
	device(std::string){};
	device (date ) {};
  	
};

int main()
{
	std::string word("helloworld");
//	date oda1;
	date today(5, "may", 2017);
 	device d1=5;
	device od2='A';
	device od3=true;
	device od4=12020202L;
	device od5=od2;
	device od6=word;
	device od7=today;		

}

