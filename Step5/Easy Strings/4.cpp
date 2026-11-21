#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];
    string st = "";
    string s1 = strs[0];
    string s2 = strs[1];
    for(int j = 0; j<min(s1.length(),s2.length()); j++)
    {
        if(s1[j] == s2[j]) st+=s1[j];
        else break;
    }
    if(st == "") return st;
    for(int i = 2; i<strs.size(); i++)
    {
        string temp = "";
        for(int j = 0; j<min(st.length(),strs[i].length()); j++)
        {
            if(st[j] == strs[i][j]) temp+=st[j];
            else break;
        }
        st = temp;
        if(temp == "") break;
    }
    return st;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    vector<string> strs;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    cout<< longestCommonPrefix(strs)<<endl;
    return 0;
}
