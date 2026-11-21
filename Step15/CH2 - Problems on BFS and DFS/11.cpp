#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()); 
        queue<vector<string>> q; 
        vector<string> level; 
        vector<vector<string>> res; 
        q.push({beginWord}); 
        level.push_back(beginWord); 
        int lev = 1; 
        while(!q.empty()){
            vector<string> ans = q.front(); 
            q.pop(); 
            if(!res.empty() && ans.size() > res[0].size()) continue;
            if(ans.size() > lev){
                lev = ans.size();
                for(auto word : level)
                    st.erase(word);
                level.clear();
            }
            string word = ans.back(); 
            if(word == endWord){
                if(!res.empty() && ans.size() > res[0].size()) break;
                if(res.empty())
                    res.push_back(ans);
                else if(ans.size() == res[0].size())
                    res.push_back(ans); 
            }
            else{
                for(int i = 0; i<word.length();i++){
                    char original = word[i]; 
                    for(char ch = 'a'; ch<='z'; ch++){
                        if(ch == original) continue;
                        word[i] = ch; 
                        if(st.find(word) != st.end()){
                            vector<string> newans = ans; 
                            newans.push_back(word); 
                            q.push(newans); 
                            level.push_back(word); 
                        }
                    }
                    word[i] = original; 
                }
            }
        }
        return res; 
    }
};
int main(){
    string beginWord, endWord; 
    cin >> beginWord >> endWord; 
    int n; 
    cin >> n; 
    vector<string> wordList(n); 
    for(int i = 0; i<n; i++) cin >> wordList[i]; 
    Solution ob; 
    vector<vector<string>> res = ob.findLadders(beginWord, endWord, wordList); 
    for(auto vec : res){
        for(auto word : vec) cout << word << " "; 
        cout << endl;
    }
}