#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<queue>
using namespace std;

vector<string> findNeigh(string ele) {
    vector<string> tmp;
    for (int i =0; i<4; ++i) {
          string play = ele;
          play[i] = (ele[i] - '0' +1) % 10 + '0';
          tmp.push_back(play);
          cout<<"Element is "<<play<<endl;
          play[i] = ((ele[i] - '0' + 9) %10) + '0' ;
          cout<<"Dec Element is "<<play<<endl;
          tmp.push_back(play);
    }           
    return tmp;
}

int main()
{
	string in ="0000";
        string target="0202";
        unordered_set<string> deadends{"0201", "0101", "0102", "1212", "2002"};
        queue<string> que;
        unordered_set<string> visited;

        que.push(in);
        visited.insert(in);  
        int res = 0;

        while (!que.empty()) {
             
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                string ele = que.front();
                que.pop();
                cout<<"Queue Element "<<ele<<endl;
                vector<string> neigh = findNeigh(ele);
                vector<string>::iterator itr = neigh.begin();
                for (; itr != neigh.end(); ++itr) {
                    if (target == *itr) {
			cout<<"Target is reached with steps "<< ++res<<endl;
			return 0;
                    }
                    if (deadends.find(*itr) != deadends.end()) {
			// If it is a deadend then iterate the next  	
                       continue;
                    }
                    if (visited.find(*itr) == visited.end()) {
			// If it is not visited, push to the queue and mark it is visited
                    	que.push(*itr);
		        visited.insert(*itr);	 
                    } 
                }  
            }   
            ++res;

        }          
        return 0;     

}
