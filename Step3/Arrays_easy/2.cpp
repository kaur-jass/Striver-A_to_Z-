#include<bits/stdc++.h>
using namespace std;

int smaxx(int arr[], int n)
{
    int max = arr[0];
    for(int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int smax = INT_MIN; // Initialize second maximum to the smallest possible integer
    for(int i = 0; i < n; i++)
    {
        if (smax < arr[i] && arr[i] != max)
        {
            smax = arr[i];
        }
    }
    return smax;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The Second largest element in the array is " << smaxx(arr,n);
    return 0;
    
}