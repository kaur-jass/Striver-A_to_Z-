#include<bits/stdc++.h>
using namespace std;

void armstrong(int x)
{
    int n;
    n = x;
    int sum = 0;
    int temp = x;
    int count = 0;
    while(temp>0)
    {
        temp = temp/10;
        count++;
    }
    while(x>0)
    {
        int ld = x%10;
        x = x/10;
        sum = sum + pow(ld,count);
    }
    if (sum == n) {
        cout << "The Given Number is an armstrong number" << endl;
    }
    else {
        cout << "The Given Number is not an armstrong number" << endl;
    }
}

int main()
{
    int x;
    cout << "Enter the Number : " << endl;
    cin >> x;
    armstrong(x);
    return 0;
}