#include <iostream>
#include<unordered_map>
using namespace std;

void print(unordered_map<int,int> ip) {
      auto itr1 = ip.begin();
      for (; itr1 != ip.end(); ++itr1) {
            cout<<"Slot no: "<<itr1->first<<" car id: "<<itr1->second<<endl;
      }
}

void shuffle(unordered_map<int,int> ip, unordered_map<int,int> op) {
 	int eslot = -1;
	auto itr1 = ip.begin();
	auto itr2 = op.begin();
	cout<<"Input given===="<<endl;
	print(ip);
	cout<<"Expected o/p====="<<endl;
	print(op);
	cout<<endl;
	for (; itr1 != ip.end(); ++itr1) {
	//	cout<<"Slot no: "<<itr1->first<<" car id: "<<itr1->second<<endl;
		if (itr1->second == -1) {
			eslot = itr1->first;
			break;
		}
	}
	itr1 = ip.begin();
	for ( ; itr1 != ip.end(); ++itr1, ++itr2) {
		if (itr1->second == itr2->second ) {
			continue;
		}
		if (itr2->second == -1) {
			ip[eslot] = itr1->second;
			itr1->second = -1;
			eslot = itr1->first;
		}

		ip[eslot] = itr1->second;
		itr1->second = -1;
		eslot = itr1->first;
		auto itr3 = ip.begin();
		for ( ; itr3 != ip.end(); ++itr3) {
			if (itr3->second == itr2->second) {
				ip[eslot] = itr2->second;
				eslot = itr3->first;
				itr3->second = -1;
				break;	
			}
		}
		cout<<"iteration 1 ==="<<"Empty slot "<<eslot<<endl;
		//print(ip);	
	}
	cout<<"==Final o/p computed ====="<<endl;
	print(ip);
}

int main()
{
#if 0
	unordered_map<int,int> input = { {0,3}, // {slot id, car id}
				    	 {1,2},
	                                 {2, 1},
        	                         {3, -1} };
#if 0
	unordered_map<int,int> output = { {0,1},
					  {1,2},
					  {2,3},
					  {3, -1} };
#endif
#if 1
      unordered_map<int,int> output = { {0, -1},
                                         {1,3},
                                         {2,2},
                                         {3, 1} };
#endif
#endif
#if 0
	unordered_map<int,int> input = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,-1}};
	unordered_map<int,int> output = {{0,2}, {1,3}, {2,4}, {3,1}, {4,5}, {5,-1}};
	unordered_map<int,int> input = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,-1}};
	unordered_map<int,int> output = {{0,-1}, {1,5}, {2,4}, {3,3}, {4,2}, {5,1}};
#endif
	unordered_map<int,int> input = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,-1}};
        unordered_map<int,int> output = {{0,2}, {1,1}, {2,4}, {3,3}, {4,-1}, {5,5}};
  
	shuffle(input, output);
	return 0;

}
