#include<iostream>
#include<string>
#include<queue>
using namespace std;

void showpq(priority_queue< pair<int,int>,
                          vector<pair<int,int> >,
                          greater<pair<int,int> > > &qu) {
#if 0
  while (!qu.empty()) {
       cout<<qu.top()<<" ";
       qu.pop();
  }
#endif
  cout<<"calling show \n";
  cout<<qu.top().first<<" "<<qu.top().second; 
  return;
}

void showp(priority_queue<int> &qu) {

  while (!qu.empty()) {
       cout<<qu.top()<<" ";
       qu.pop();
  }
  return;
}

int main()  {

	priority_queue<int> qu;
	priority_queue< pair<int,int>, 
                        vector<pair<int,int> >, 
                        greater<pair<int,int> > >  min;
	qu.push(5);
	min.push(make_pair(6,1));
	qu.push(6);
	min.push(make_pair(5,1));
	qu.push(7);
	qu.push(8);

	showp(qu);
	showpq(min);
 	
	return 0;
}
