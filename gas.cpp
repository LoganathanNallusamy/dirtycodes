#include<iostream>
#include<vector>
using  namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        int s = gas.size();
        int start = -1;
        int i = 0;
        for ( i = 0; i < s; ++i) {
            
            if (gas[i] >= cost[i]) {
                start = i;
                int p= 0;
                int j=0;
	        int ii = i;
                while (j  < s) {
                   ii = ii%s;
                   p += gas[ii];
                   if ( p < cost[ii]) break;
                   p -= cost[ii];
                   ++ii;
		   ii = ii%s; 	
                   if ( ii == start) return start;
                   j++;
                }
		start = -1;
           }

        }
        return start;
        
    }
};

int main() {
	Solution s;
	vector<int> gas{2};
	vector<int> cost{2};
	cout<<"The result is "<<s.canCompleteCircuit(gas,  cost)<<endl;
	return 0;
}
