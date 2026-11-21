#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string str1 = "shradha";
    string str2 = "khapra";  // Strings are compared lexographically 
    cout << str1.length() << endl;
    cout << (str1 <str2) << endl;
    return 0;
    
}