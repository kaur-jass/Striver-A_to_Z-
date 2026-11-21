#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
    int n = s.length();
    long long number = 0; 
    string t = "";
    int ans = 0;
    int sign = 1;
    for(int i = 0; i<n; i++)
    {
    if(s[i] != ' ') 
    {
        ans = i;
        break;
    }    
    }
    if(s[ans] == '+' || s[ans] == '-')
    {
    if(s[ans] == '-') sign = -1; 
        ans++;                      // this one is need to check   
    }
    for(int i = ans; i<n; i++)
    {
        if(!isdigit(s[i])) break;
        else t += s[i];
    }
    t.erase(0,t.find_first_not_of('0')); // This is the built in function used to remove leading zeroes or else u need to use while loop to check first non zero digit 
    for(int i = 0; i <t.length(); i++)
    {
    number = number*10 +(t[i]-'0'); // ascii values 
    if(number >INT_MAX) break;
    }  
    if (sign * number < INT_MIN) return INT_MIN; // these are the basic edge cases u need to check properly 
    if (sign * number > INT_MAX) return INT_MAX;  
    return sign*number;
}

int main()
{
    string s; 
    getline(cin, s);
    cout << myAtoi(s) << endl;
    return 0;
}