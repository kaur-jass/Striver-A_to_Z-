#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    if(n == 1) return; // Base case: if the array has only one element, it's already sorted.
    int didswap = 0;
    for (int j = 0; j<= n-1;j++)
    {
        if(arr[j] > arr[j+1]) 
        {
            swap(arr[j],arr[j+1]);
            didswap = 1;
        }
    }
    if(didswap == 0) return; 
    bubble_sort(arr, n-1);
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
    bubble_sort(arr,n);
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}