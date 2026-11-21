#include<bits/stdc++.h>
using namespace std;
// Reversing an array using two pointers 


void reversing_array(vector<int>& arr, int l,int r)
{
    if(l >= r) return;
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    reversing_array(arr, l+1,r-1);
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reversing_array(arr, 0,n-1);

    cout << "The reversed array is : ";
    for(int i = 0;i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
