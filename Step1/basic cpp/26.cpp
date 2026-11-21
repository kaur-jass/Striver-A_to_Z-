#include<bits/stdc++.h>
using namespace std;


// pass by reference

void dosomething(string &s){
    s[0] = 'T';
    cout << s << endl;
}
int main()
{
    string s = "Raj";
    cout << s << endl;
    dosomething(s);  
    cout << s << endl;
    return 0;  
}