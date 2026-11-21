#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int l = word.length(); 
        long long cnt = 0; 
        int mask = 0; 
        vector<int> freq(1 << 10, 0);
        freq[0] = 1; 
        for(int i = 0; i<l; i++){ 
            int idx = word[i] - 'a'; 
            mask ^= (1 << idx);
            cnt += freq[mask]; 
            for(int k = 0; k<10; k++){
                int new_mask = mask ^ (1 << k);
                cnt += freq[new_mask]; 
            }
            freq[mask]++; 
        }
        return cnt; 
    }
};

int main() {
    Solution sol;
    string s = "aba";
    cout << sol.wonderfulSubstrings(s) << endl;
    return 0;
}
