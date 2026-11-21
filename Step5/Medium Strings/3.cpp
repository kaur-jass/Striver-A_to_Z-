#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
    int sum = 0;
    unordered_map<char,int> roman = { 
    {'I',1},{'V',5},{'X',10},{'L',50},
    {'C',100},{'D',500},{'M',1000}
    };
    for(int i = 0; i < s.length(); i++)
    {
        if(roman[s[i]]<roman[s[i+1]]) sum -=roman[s[i]];
        else sum += roman[s[i]];
    }  
    return sum;
}

int main()
{
    string s; 
    getline(cin, s);
    cout << romanToInt(s) << endl;
    return 0;
}