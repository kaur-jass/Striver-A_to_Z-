#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()); 
        queue<pair<string, int>> q; 
        q.push({beginWord, 1}); 
        while(!q.empty()){
            auto[word, steps] = q.front(); 
            q.pop(); 
            if(word == endWord) return steps; 
            else{ // need to generate all the possible next words; 
                for(int i = 0; i<word.length(); i++){
                    char original = word[i]; 
                    for(char ch = 'a'; ch<='z'; ch++){
                        word[i] = ch; 
                        if(st.find(word) != st.end()){
                            q.push({word, steps+1}); 
                            st.erase(word); 
                        }
                        word[i] = original; 
                    }  
                }
            }
        }
        return 0; 
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
    cout << ob.ladderLength(beginWord, endWord, wordList) << endl;
}