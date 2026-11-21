#include<bits/stdc++.h>
using namespace std;
/*
A school has following rules for grading system: 
a. Below 25 - F 
b. 25 to 44 - E 
c. 45 to 49 - D 
d. 50 to 59 - C 
e. 60 to 79 - B 
f. 80 to 100 - A 
Ask user to enter marks and print the coresspomdingg grades 
*/
int main()
{
    int x ;
    cout << "Enter Marks : ";
    cin >> x;
    if (x <=100 && x >= 80)
    {
        cout << "Grade A" << endl;
    }
    else if (x <= 79 && x >= 60)
    {
        cout << "Grade B" << endl;
    }
    else if (x <= 59 && x >= 50)
    {
        cout << "Grade C" << endl;
    }
    else if (x <= 49 && x >= 45)
    {
        cout << "Grade D" << endl;
    }
    else if (x <= 44 && x >= 25)
    {
        cout << "Grade E" << endl;
    }
    else 
    {
        cout << "Grade F" << endl;
    }
    return 0;
}