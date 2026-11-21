#include<bits/stdc++.h>
using namespace std;
string largestOddNumber(string num) {
    int n = num.size();
    string s = "";
    for(int i = n-1; i>= 0; i--)
    {
        if((num[i]-'0')%2 == 0) continue;
        else
        {
            s = num.substr(0,i+1);   // This i+1 is the length of the substring... so starting from index zero it will calculate the length of the substring u want to print.....
            break;
        }
    }
    return s; 
}

int main()
{
    string s;
    getline(cin,s);
    cout << largestOddNumber(s) << endl;
    return 0; 
}