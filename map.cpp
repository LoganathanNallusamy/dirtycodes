#include<iostream>
#include<map>
using namespace std;


int main()
{
	map<char, int> m;
	m.insert(pair<char,int>('c', 3));
	
	map<char, int>::iterator itr = m.begin();
	m['c'] = 31;
	for (; itr != m.end(); ++itr) {
		cout<<"Char is "<<itr->first<<"  Interger is "<<itr->second<<"  Address "<<&(itr->second)<<endl;
		itr->second = 100;		
		itr->second = 838;		
	}
	itr = m.begin();
	cout<<"The map after modifying is \n";
	for (; itr != m.end(); ++itr) {
		cout<<"Char is "<<itr->first<<"  Interger is "<<itr->second<<"  Address "<<&(itr->second)<<endl;
	}

	itr  = m.find('c');
	if (itr != m.end()) {
		cout<<"Modifying  the value via find"<<endl;
		cout<<"Char is "<<itr->first<<"  Interger is "<<itr->second<<"  Address "<<&(itr->second)<<endl;
		itr->second = 55;	
		cout<<"Char is "<<itr->first<<"  Interger is "<<itr->second<<"  Address "<<&(itr->second)<<endl;
	}

	pair<std::map<char,int>::iterator , bool> ret = m.insert(pair<char, int>('c', 11));
	if (ret.second == false) {
		cout<<"insertion faile"<<endl;
		ret.first->second = 51;

	}	
	itr = m.begin();
	for (; itr != m.end(); ++itr) {
		cout<<"Char is "<<itr->first<<"  Interger is "<<itr->second<<"  Address "<<&(itr->second)<<endl;
	}
	return 1;

}
