#include<bits/stdc++.h>
#include<bits/stdc++.h> // This header file includes all the standard libraries
using namespace std;
// write a program that takes an input of age 
// and print if you are adult or not 
// >= 18, yes 
// < 18, no
int main()
{
    int age;
    cout << " Enter your age : ";
    cin >> age;
    if (age >=18)
    {
        cout << "You are an adult" << endl;  
    }
    else 
    {
        cout << "You are not an adult" << endl;
    }
    return 0;
}