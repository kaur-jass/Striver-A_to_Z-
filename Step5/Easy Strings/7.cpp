#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
    unordered_map<char, int> mpp1; 
    unordered_map<char, int> mpp2;
    for(int i = 0; i<s.length(); i++)
    {
        mpp1[s[i]]++;
    }
    for(int i = 0; i<t.length(); i++)
    {
        mpp2[t[i]]++;
    }
    if(mpp1 == mpp2) return true; 
    return false;
}

int main()
{
    string s; 
    getline(cin, s);
    string goal;
    getline(cin, goal);
    cout << (isAnagram(s, goal) ? "YES" : "NO");
    return 0;
}