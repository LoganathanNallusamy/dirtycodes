#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> xx {-1,1,0,0};
    vector<int> yy {0,0,1,-1};
    bool validate(vector<vector<char>> &board, int x, int y) {
        int r = board.size();
        if ( x < r && x >= 0) {
            if ( y < board[x].size() && y >= 0) {
                return true;
            }
        }
        return false;
    }
    void util(vector<vector<char>>& board,int i, int j, vector<string>& words, 
                       vector<vector<int>> &visited, vector<string> &result, string &add) {
        
        
        auto itr = find(words.begin(), words.end(), add) ;
        if (itr != words.end()) {
	    cout<<"Pushing "<<add<<endl;
            result.push_back(add);
        }

        for (int it = 0; it < 4; ++it) {
                int x1 = i + xx[it];
                int y1 = j + yy[it];
//		cout<<"validate "<<x1<<","<<y1<<endl;
                if (validate(board, x1, y1) && 
                    !visited[x1][y1] ) {

                    visited[x1][y1] = 1;
                    char c = board[x1][y1];
		    add.push_back(c);
//		    cout<<"Add is now "<<add<<endl;
                    util(board, x1, y1, words, visited, result, add);
                    visited[x1][y1] = 0;
                    add.pop_back();
                }
        }
       
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      
       
        int s = 0;
        if (board.size()) {
            s = board.size() * board[0].size();
        }
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0)); 
        string add;
        vector<string> result;
        for (int i = 0; i < board.size(); ++i){
            for (int j=0; j < board[i].size(); ++j){
                 if (visited[i][j] == 0) {
                    add.push_back(board[i][j]);
		    visited[i][j] = 1;
                    util(board, i, j, words, visited, result, add); 
                    add.pop_back();
		    visited[i][j] = 0;
                 }
                 
            }
        }
        cout<<"size of result is "<<result.size()<<endl; 
        return result;
        
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
  {'o','a','a','n'},
  {'e','t','a','e'},
  {'i','h','k','r'},
  {'i','f','l','v'}
};

    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> str = s.findWords(board, words);		
    return 0l;


}
