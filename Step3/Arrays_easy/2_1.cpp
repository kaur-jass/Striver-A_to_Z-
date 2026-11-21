#include<bits/stdc++.h>
using namespace std;

int second_largest(vector<int> arr, int n)
{
   int largest = arr[0];
   int slargets = INT_MIN; // Initialize second largest to the smallest possible integer
   for(int i = 0; i<n; i++)
   {
         if (largest < arr[i])
         {
              slargets = largest; // Update second largest before changing largest
              largest = arr[i];
         }
         else if(arr[i] < largest && arr[i] > slargets)
         {
              slargets = arr[i];
         }
   }
   return slargets;
}

int second_smallest(vector<int> arr, int n)
{
    int smallest = arr[0];
    int ssmallest = INT_MAX; // Initialize second smallest to the largest possible integer
    for(int i = 0; i<n; i++)
    {
        if (smallest > arr[i])
        {
            ssmallest = smallest; // Update second smallest before changing smallest
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < ssmallest)
        {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

pair<int, int> get_second_order_element(vector<int>& arr, int n)
{
    int slargest = second_largest(arr, n);
    int ssmallest = second_smallest(arr, n);
    return {ssmallest, slargest}; // ✅ now valid
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pair<int, int> result = get_second_order_element(arr, n);
    cout << "The Second smallest element in the array is " << result.first << endl;
    cout << "The Second largest element in the array is " << result.second << endl;
    return 0;
    
}