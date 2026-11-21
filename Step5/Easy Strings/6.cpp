#include<bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal) {
    int n = s.length();
    for(int k = 1; k<=n; k++)
    {
        string t = s; 
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+k);
        reverse(s.begin()+k, s.end());
        if(s == goal) return true; 
        else s = t; 
    }
    return false;
}

int main()
{
    string s; 
    getline(cin, s);
    string goal;
    getline(cin, goal);
    cout << (rotateString(s, goal) ? "YES" : "NO");
    return 0;
}