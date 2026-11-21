#include<bits/stdc++.h>
using namespace std;

vector<int> repeating_and_missing(vector<int> &nums)
{
    int n = nums.size();
    vector<int> hash(n+1,0);
    vector<int> ans; 
    for(int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }
    for(int i = 1; i<=n; i++)
    {
        if(hash[i] == 0) ans.push_back(i); // To check which no is the repeating number in the array 
        if(hash[i] == 2) ans.push_back(i); // To check which no is the missing number in the array 
    }
    return ans; 
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
    vector<int> temp = repeating_and_missing(arr);
    for(int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    return 0;
}