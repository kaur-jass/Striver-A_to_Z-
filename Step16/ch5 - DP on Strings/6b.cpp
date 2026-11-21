#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prev, curr; 
public:
    int minDistance(string word1, string word2) {
      int n = word1.length(); 
      int m = word2.length(); 
      prev.assign(m, 0);
      curr.assign(m, 0);

      // using space optimization to find the longest common subsequence
      for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
              if(word1[i] == word2[j]){
                  curr[j] = 1 + (i>0 && j>0 ? prev[j-1] : 0); 
              } else {
                  curr[j] = max(i>0 ? prev[j] : 0, j>0 ? curr[j-1] : 0); 
              }
          }
        prev = curr;
      }
       return n + m - 2*curr[m-1]; // total deletions i need from both word1 and word2 
    }
};

int main(){
    string word1, word2; 
    cin >> word1 >> word2; 
    Solution obj; 
    cout << obj.minDistance(word1, word2) << endl; 
    return 0; 
}