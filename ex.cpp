#include <iostream>
#include<unordered_map>
using namespace std;

void print(unordered_map<int,int> ip) {
      auto itr1 = ip.begin();
      for (; itr1 != ip.end(); ++itr1) {
            cout<<"Slot no: "<<itr1->first<<" car id: "<<itr1->second<<endl;
      }
}
void printcartoslot(unordered_map<int,int> ip) {
      auto itr1 = ip.begin();
      for (; itr1 != ip.end(); ++itr1) {
            cout<<"Car id "<<itr1->first<<" slot no "<<itr1->second<<endl;
      }
}

void shuffle(unordered_map<int,int> ip, unordered_map<int,int> op) {
        int eslot = -1;
        auto itr1 = ip.begin();
        auto itr2 = op.begin();
	int size = 0;
	#if 1
        cout<<"===Input given===="<<endl;
        print(ip);
        cout<<"===Expected o/p====="<<endl;
        print(op);
	#endif
	unordered_map<int,int> cartoslot;
	
        cout<<endl;
        for (; itr1 != ip.end(); ++itr1, itr2++) {
		++size;
                if (itr1->second == -1) {
                        eslot = itr1->first;
                } else if ( itr2->second != -1){
		       cartoslot.insert( {itr2->second, itr2->first} );
		}
        }
	cout<<"=====Car to slot i/p==="<<endl;
	printcartoslot(cartoslot);
        cout<<endl;
	
        itr1 = ip.begin();
	itr2 = op.begin();
	int j = 1;
        for ( ; j <= size; ++itr1, ++itr2, ++j) {
		cout<<"Iteration "<<j<<" startng"<<" acting on slot "<<itr1->first<<" car "<<itr1->second<<" "<<itr2->second<<endl;
		if (itr2->second != -1) {
			int toslot = cartoslot[itr2->second];
			int toslotexisticar = ip[toslot];
			if (eslot == toslot) {
				ip[toslot] = itr1->second;
				eslot = itr1->first;
				itr1->second = -1;	
			} else {
				ip[eslot] = toslotexisticar;
				ip[toslot] = -1;
				eslot = toslot;

				ip[toslot] = itr1->second;
				itr1->second = -1;
				eslot = itr1->first;		
			}	
		}
		cout<<"Empty slot at end"<<eslot<<endl;
		print(ip);
		cout<<endl;
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
        unordered_map<int,int> output = { {0,1},
                                          {1,2},
                                          {2,3},
                                          {3, -1} };
#if 0
      unordered_map<int,int> output = { {0, -1},
                                         {1,3},
                                         {2,2},
                                         {3, 1} };
#endif
#endif
#if 0
        unordered_map<int,int> input = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,-1}};
        unordered_map<int,int> output = {{0,2}, {1,3}, {2,4}, {3,1}, {4,5}, {5,-1}};
#endif
        unordered_map<int,int> input = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,-1}};
        unordered_map<int,int> output = {{0,-1}, {1,5}, {2,4}, {3,3}, {4,2}, {5,1}};
	
#if 0
        unordered_map<int,int> input = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,-1}};
        unordered_map<int,int> output = {{0,2}, {1,1}, {2,4}, {3,3}, {4,-1}, {5,5}};

#endif
        shuffle(input, output);
        return 0;

}
                                   
