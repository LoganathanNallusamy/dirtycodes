#include<iostream>
#include<string>
#include<vector>
using namespace std;

class check
{
private:
	int t = true, f = false;
public:
	check(int a,int b): t(move(a)),f(move(b)) {
		cout<<"I am constructed\n";
	}
	check & operator=(check &&s) {
		t = s.t;
		f = s.f;
		cout<<"I am move assigned\n";
		s.t = 0;
		s.f = 0;
		return *this;
	}
	check & operator=(const check &s) {
		t = s.t;
		f = s.f;
		cout<<"I am copy assigned\n";
		return *this;
	}
	check(const check &b) {
	   t = b.t;	
	   f = b.f;
	   cout<<"I am copy constructed\n";
	}
#if 1
	check(const check &&b) {
	   t = b.t;	
	   f = b.f;
	   cout<<"I am moved \n";
	}
#endif
	~check() {
	    cout<<"I am destructed"<<endl;
	}
};

check get() {
	check g(5,6);
	return g;
}
int main()
{
//	check c(1,2);
	//cout<<"executing copy \n";
//	check d(c);
	vector<check> list, list1;

#if 0
	cout<<"===Emplace back start ==="<<endl;
	list.emplace_back(check(1,2));
	cout<<"===Emplace back end==="<<endl;
	cout<<"===insert list start==="<<endl;
	list1.push_back(check(1,2));
	cout<<"===insert list end==="<<endl;
#endif
	check d(9,9);
	cout<<"D constructed \n";
	d = get();
	cout<<"D end cons\n";
	return 0;
}

