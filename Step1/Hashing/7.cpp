#include<bits/stdc++.h>
using namespace std;
//unordered map
int main()
{
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int,int> mpp;
    // precomputation can be done while taking input also 
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }


    // Iterate in the map and print the elements 
    for(auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;

    }

    int q;
    cin >> q;
    while(q--)
    {
        int number;
        cin >> number;
        //fetch 
        cout << mpp[number] << endl;
    }
}