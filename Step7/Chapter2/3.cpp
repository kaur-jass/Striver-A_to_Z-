#include <bits/stdc++.h>
using namespace std;

// Solution class to generate all subsequences using recursion
class Solution {
public:
    // Helper recursive function to generate subsequences
    void helper(string &s, int index, const string &current, vector<string> &result) {
        // Base case: If index reaches string length, add current subsequence to result
        if (index == s.size()) {
            result.push_back(current);
            return;
        }

        // Exclude current character and recurse
        helper(s, index + 1, current, result);

        // Include current character and recurse
        string newCurrent = current + s[index];
        helper(s, index + 1, newCurrent, result);
    }
;
    // Function to return all subsequences of string s
    vector<string> getSubsequences(string s) {
        // Vector to store all subsequences
        vector<string> result;  
        // Current subsequence being built
        string current = "";    
        helper(s, 0, current, result);
        return result;
    }
};

int main() {
    // Input string
    string s = "abc";

    // Create Solution object
    Solution sol;

    // Get all subsequences
    vector<string> subsequences = sol.getSubsequences(s);

    // Print all subsequences
    for (auto &subseq : subsequences) {
        cout << "\"" << subseq << "\"" << endl;
    }

    return 0;
}