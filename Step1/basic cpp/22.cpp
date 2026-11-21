#include<bits/stdc++.h>
using namespace std;
//return 
// Que - Take two NUmbers and print its sum;

int sum(int a,int b)
{
    return a+b;
}
int main()
{
    int x,y;
    cout<< "Enter the Value of x and y : " << endl;
    cin >> x >> y;
    cout << "The Sum of the two numbers is : " << sum(x,y) << endl;
    return 0;
}