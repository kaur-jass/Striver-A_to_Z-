#include<bits/stdc++.h>
using namespace std;


// pass by value 

void dosomething(string s){
    s[0] = 'T';
    cout << s << endl;
}
int main()
{
    string s = "Raj";
    dosomething(s);  
    cout << s << endl;
    return 0;  
}