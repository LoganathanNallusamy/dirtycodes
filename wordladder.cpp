#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
#include<deque>

using namespace std;
class Solution 
{
public:
    int min = INT_MAX;
    int diff(string s1, string s2) {
        int n = s1.size();
        int re = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ++re;
            }
        }
        return re;
    }
    void compute(string beginWord, string endWord, vector<string > &wordList, vector<bool> &visited, int re, deque<string> &q) {
	 cout<<"start of compute "<<beginWord<<endl;
        if (beginWord == endWord) {
	    for (int j =0; j < q.size(); ++j) {
		cout<<"--> "<<q[j]<<" ";
	    }
            cout<<" Reached "<<endl;
            re++;
            min = min < re ? min:re;
            return;
        }
        for (int i = 0; i < wordList.size(); ++i) {
             if ((diff(beginWord, wordList[i]) == 1) && (!visited[i])) {
                 visited[i] = true;
                 ++re;
		 q.push_back(wordList[i]);
                 compute(wordList[i], endWord, wordList, visited, re, q);
                 --re;
		 q.pop_back();
            //     visited[i] = false;
             }
         }
	 cout<<"End of compute "<<beginWord<<endl;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int re = 0;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() ) {
            return re;
        }
        vector<bool> visited(wordList.size(), false);
        deque<string> q; 
        compute(beginWord, endWord, wordList,visited, re, q);
 						        
        return min;
    }
};

int main() {

	string begin{"qa"};
	string end{"sq"};

	vector<string> wlist{"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	Solution s;
	cout<<"Result is "<<endl<<s.ladderLength(begin, end, wlist)<<endl;
	return 0;
}
