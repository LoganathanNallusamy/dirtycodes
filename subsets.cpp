#include<iostream>
#include<vector>
#include<string>

using namespace std;

void
f(vector<int> &nums, int tar,  vector<int> &tmp, vector<vector<int>> &res) {
	if (nums.size() == tar) {
		cout<<"Size "<<tmp.size()<<endl;
		res.push_back(tmp);
		return;
	}
	tmp.push_back(nums[tar]);
	f(nums, tar +1, tmp, res);
	tmp.pop_back();
	f(nums, tar +1, tmp, res);

}


vector<vector<int>> subsets(vector<int> &nums) {

	vector<vector<int>> res;
	vector<int> tmp;
	
	f(nums, 0, tmp, res);
	cout<<"The subsets are "<<endl;
	for (int i = 0; i < res.size(); ++i){
	   for (int j = 0; j < res[i].size(); ++j) {
		cout<<res[i][j]<<" ";

	   }
	   cout<<endl;
	}	
	return res;
}

int main() {

	vector<int> nums{31,32,13};
	subsets(nums);
	return 0l;

}
