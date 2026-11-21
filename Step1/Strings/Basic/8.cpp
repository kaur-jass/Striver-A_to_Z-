#include<iostream> 
#include<cstring>
using namespace std;

int main()
{
    string str1 = "Apna ";
    string str2 = "College";

    string str3 = str1+str2; // Concatenation 
    cout << str3 << endl;

    string str4 = "Jaspreet";
    string str5 = "Jaspreet";
    cout << (str5 == str4) << endl;
    return 0;
}