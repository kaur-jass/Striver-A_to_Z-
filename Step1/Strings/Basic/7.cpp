#include<iostream> 
#include<cstring>
using namespace std;

int main()
{
    string str = "Apna College"; //Strings are dynamic in nature  // Runtime resize 
    cout << str << endl;
    str = "Hello";
    cout << str << endl;

    char arr[] = "Apna College";
    // arr = "Hello";   // expression must be a modifiable lvalue i.e. it cannot be modified.....
    return 0;
}