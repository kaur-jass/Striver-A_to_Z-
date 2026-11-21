#include<bits/stdc++.h>
using namespace std; 

bool isPalindrome(string s)
{
    int n = s.size();
    string str = s;
    reverse(str.begin(),str.end());
    if(s == str) return true;
    return false;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Output : " << isPalindrome(s) << endl;
    return 0;
}