#include<bits/stdc++.h>
using namespace std;
// arrays are always pass by reference not pass by value 

void dosomething(int arr[],int n)   
{
    arr[0] += 100;
    cout << "Value Inside Function : " << arr[0] << endl;
}

int main()
{
    int n = 5;
    int arr[n];
    for (int i = 0; i<n;i++)
    {
        cin >> arr[i];
    }
    dosomething(arr,n);

    cout << "Value Inside int main : " << arr[0] << endl;
    return 0;
}