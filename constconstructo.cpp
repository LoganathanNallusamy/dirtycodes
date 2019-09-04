#include <iostream>
using namespace std;

class date
{
   public:
	date():pi(3.14){};
  	//date(int a, std::string s, int c):pi(3.14) {};
  	date(int a, std::string s, int c) {};
  	//date(int a, std::string s, int c){};
  private:
	int day;
	char month[4];
	int year;
	const double pi;
};

int main()
{
	date oda1(1,"monthmay",20);


}

