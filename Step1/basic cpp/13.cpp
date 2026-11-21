#include<bits/stdc++.h>
using namespace std;
/*
 Take the age from the user and decide accordingly 
 1. if age < 18
 print -> not eligible for job 
 2. If age >= 18 and age <= 54
 print -> "Eligible for job"
 3. If age <= 55 and age <= 57
 print -> "Eligible for job but retirement soon"
 4. If age > 57 
 print -> "retirement time"
*/
int main()
{
    int x;
    cout << "Enter your age : " << endl;
    cin >> x;
    if (x < 18)
    {
        cout << "You are not eligible for job" << endl;
    }
    // x >= 18
    else if (x <=57)
    {
        cout << "You are eligible for job" << endl;
        if (x >= 55)
        {
            cout << "You are eligible for job but retirement soon" << endl;
        }
    }
    else 
    {
        cout << "Retirement Soon";
    }
    return 0;
}
