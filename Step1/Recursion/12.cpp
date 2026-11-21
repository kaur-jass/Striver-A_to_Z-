#include<bits/stdc++.h>
using namespace std;


string removeds(const string& input)
{
    string result;
    for(char ch : input)
    {
        if(isalpha(ch) || isdigit(ch)){
            result += tolower(ch);
        }
    }
    return result;
}

bool ispalin(const string& str, int i)
{
    int n;
    n = str.size();
    if(i >= n/2) return true;
    if(str[i] != str[n-i-1]) return false;
    return ispalin(str,i+1);
}
bool isPalindrome(string s) {
    string str = removeds(s);
    return ispalin(str,0);
}

int main() {
    
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    if (isPalindrome(s))
        cout << "Palindrome!" << endl;
    else
        cout << "Not a palindrome." << endl;
    return 0;
}
