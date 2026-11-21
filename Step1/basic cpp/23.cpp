#include<bits/stdc++.h>
using namespace std;

int maxx(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
   
}
int main()
{
    int num1,num2;
    cin >> num1 >> num2;
    int minimum = min(num1,num2);
    cout << "The minimum number is : " << minimum << endl;
    int maximum = maxx(num1,num2);
    cout << "The maximum number is : " << maximum << endl;
    return 0;
}