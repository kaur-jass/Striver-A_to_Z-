#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 0;i<=n-1;i++)
    {
        // for (int j = i; j>=1;j--)
        // {
        //     if(arr[j] < arr[j-1]) 
        //     {
        //         swap(arr[j],arr[j-1]);
        //     }
        // }

        int j = i;
        while(j>0 && arr[j-1]>arr[j])
        {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    // I used while loop instead of for loop to make it more efficient cause at the condition checking if ot does not
    // satisfy the loop will not run giving the best case time complexity of O(n)
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    // Input the number of elements
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertion_sort(arr,n);
    cout << "Sorted array: ";
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
} 