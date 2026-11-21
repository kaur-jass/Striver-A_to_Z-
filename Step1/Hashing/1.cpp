#include<bits/stdc++.h>
using namespace std;

int f(int n, int x,vector<int> &arr)
{
    int cnt = 0;
    for(int i = 0; i < x; i++)
    {
        if (arr[i] == n) cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    cout << "Enter the Number : ";
    cin >> n;
    int x;
    cout << "Enter the Number of elements in the array : ";
    cin >> x;
    vector<int> arr(x);
    for(int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }
    cout << "The number of times " << n << " occurs in the array is " << f(n,x,arr);
}