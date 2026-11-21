#include <bits/stdc++.h>
using namespace std;

string reverseWordOrder(string s) {
    vector<string> words;
    stringstream ss(s);
    string word;

    // Step 1: Split into words
    while (ss >> word) {
        words.push_back(word);
    }

    // Step 2: Two-pointer swap
    int left = 0, right = words.size() - 1;
    while (left < right) {
        swap(words[left], words[right]);
        left++;
        right--;
    }

    // Step 3: Join words
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
    }

    return result;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWordOrder(s) << endl;
    return 0;
}
