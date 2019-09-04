#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>

using namespace std;


class solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
	
	
        if(dict.count(s)){ //a whole string is a word
	    cout<<"Pushing "<<s<<endl;
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
	    cout<<"String sub "<<word<< ",rema "<<s.substr(0,i)<<endl;
            if(dict.count(word)){
                string rem=s.substr(0,i);
		cout<<"Sting s "<<s<<" word = "<<word<<" rema = "<<rem<<endl;
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};

int main()
{
	solution s1;
	string s("catsanddog");
	unordered_set<string> dict={"Hello","World", "cat", "cats", "and", "sand", "dog"};
	vector<string> res = s1.wordBreak(s,dict);
	for (int i = 0; i < res.size(); ++i) {
		cout<<res[i]<<" "<<endl;
	}
	return 0;


}
