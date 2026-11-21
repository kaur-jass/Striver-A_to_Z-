/*
Problem statement: Given an array, we have found the number of occurrences of each element in the array.
Or it is also known as frequency array.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int,int> mpp;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    for(auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }
    return  0;
}