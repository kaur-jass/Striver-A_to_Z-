#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void hashtable(unordered_map<int, string>& mpp){
        mpp[2] = "abc"; 
        mpp[3] = "def"; 
        mpp[4] = "ghi"; 
        mpp[5] = "jkl"; 
        mpp[6] = "mno"; 
        mpp[7] = "pqrs"; 
        mpp[8] = "tuv"; 
        mpp[9] = "wxyz";
    }
    int sto(char i){
        return (i-'0');
    }
    void generate(int idx, string digits, string curr, vector<string>& result,unordered_map<int, string>& mpp){
        int n = digits.size(); 
        if(curr.size()==n){
            result.push_back(curr); 
            return;        
        }
        int cur = sto(digits[idx]); 
        string ans = mpp[cur];
        for(int i = 0; i<ans.size(); i++){ 
            curr.push_back(ans[i]); 
            generate(idx+1, digits, curr, result, mpp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        unordered_map<int, string> mpp; 
        hashtable(mpp); 
        string curr = ""; 
        vector<string> result; 
        generate(0, digits,curr,result,mpp);
        return result; 
    }
};

int main(){
    Solution sol; 
    string digits = "237"; 
    vector<string> result = sol.letterCombinations(digits); 
    cout << "The possible letter combinations are: "<<endl;
    cout << "[ ";
    for(auto str : result){
        cout<<str<<", ";
    }
    cout<<"]"<<endl;
    return 0; 
}