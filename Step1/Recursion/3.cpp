#include<bits/stdc++.h>
using namespace std;

void name(int i, int n)
{
    if(i > n) return;
    cout << "Jaspreet" << endl;
    name(i+1,n);
}

int main()
{
    int n;
    cout << "Enter the number of times you want to print your name : ";
    cin >> n;
    name(1,n);
    return 0;
}