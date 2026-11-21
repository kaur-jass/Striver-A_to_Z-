#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
    int strt = 0; 
    int end = s.size()-1; 
    transform(s.begin(),s.end(),s.begin(),::tolower);
    while(strt<=end)
    {
        if(s[strt] == s[end]) 
        {
            strt++;
            end--;    
        }
        else if(!isalnum(s[strt]))
        {
            strt++;
            continue;
        }
        else if(!isalnum(s[end]))
        {
            end--;
            continue;
        }
        else return false;
    } 
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    cout << isPalindrome(s) << endl;
    return 0;
}