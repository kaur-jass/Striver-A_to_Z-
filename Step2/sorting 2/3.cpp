#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int k,int n)
{
    if (k >= n) return; // Base case: if k is equal to or greater than n, the array is sorted.
        int j = k;
        while(j>0 && arr[j-1]>arr[j])
        {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    insertion_sort(arr, k + 1, n); // Recursive call to sort the next element.
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
    insertion_sort(arr,0,n);
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}