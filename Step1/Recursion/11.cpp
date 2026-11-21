#include<bits/stdc++.h>
using namespace std;

void f(int i, vector <int> &arr, int n)
{
    if(i >= n/2) return;
    swap(arr[i], arr[n-i-1]);
    f(i+1,arr,n);
}
int main()
{
    int n;
    cout << " Enter the number of elements in the array : ";
    cin >> n;
    vector<int> arr(n);
    cout << " Enter the elements of the array : ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    f(0,arr,n);

    cout << "The reversed array is : ";
    for(int i = 0;i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}