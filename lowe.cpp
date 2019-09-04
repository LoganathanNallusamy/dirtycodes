#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class solution {
public:
	static int func(vector<int> a, vector<int> b) {
		if (a[0] < b[0]) {
			return true;
		} else if (a[0] == b[0]) {
			if (a[1] < b[1]) {
				return true;
			} else {
				return false;
			}

		}
		return false;
 	}

	int maxEnvelop(vector<vector<int>> &env) {
		int n = env.size();
		int r = 0;
		if (n <= 0) {
		    return r;	
		} 	    
		sort(env.begin(), env.end(), func);
		cout<<"After sorting \n";
		for (int i = 0; i < n; ++i) {
			for (int j=0; j < env[i].size(); ++j) {
				cout<<env[i][j]<<" ";
			}
			cout<<endl;
		}
		vector<int> c{1,2};
		vector<vector<int>>::iterator itr = lower_bound(env.begin(), env.end(), c);

		if (itr == env.end()) {
			cout<<"returned end "<<"\n";
		} else {
			cout<<"val "<<itr[0][0]<<" "<<itr[0][1]<<" "<<endl;
		}
		return r;
        }
};

int main()
{
	solution s;
	vector<vector<int>> env{{1,2},{2,4}, {2,3}, {3,4}};
	s.maxEnvelop(env);
	return 0;
}
