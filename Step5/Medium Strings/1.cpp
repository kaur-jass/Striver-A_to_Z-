#include<bits/stdc++.h>
using namespace std;
string frequencySort(string s) {
    int n = s.length();
    string t = "";
    unordered_map<char, int> freq; 
    for(int i = 0; i<n; i++)
    {
        freq[s[i]]++;
    }
    vector<pair<char, int>> vec(freq.begin(), freq.end());   // we cannot sort hashmaps, so need to convert it into vector array.... 
    sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });   // i don't knew this thing before that this is the way of sorting vector by frequency not by characters....in descending order..... 
    for(auto& it : vec)
    {
        t += string(it.second,it.first);
    }
    return t;
}

int main()
{
string s; 
getline(cin, s);
cout << frequencySort(s) << endl;
return 0;
}