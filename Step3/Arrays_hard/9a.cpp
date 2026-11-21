#include<bits/stdc++.h>
using namespace std;
vector<int> repeating_and_missing(vector<int> &nums)
{
    long long n = nums.size(); // x = repeating no. and  y = missing no.
    long long s = 0; 
    long long sn = n*(n+1)/2;
    long long s2 = 0; 
    long long s2n = n*(n+1)*(2*n+1)/6;
    for(int i = 0; i<n; i++)
    {
        s += nums[i];
        s2 += (long long)nums[i]*(long long)nums[i];
    }
    long long val1 = s-sn;  // x-y
    long long val2 = s2-s2n; // x^2-y^2
    val2 = val2/val1; // x+y
    long long x = (val1+val2)/2;
    long long y = x-val1;
    return{(int)x,(int)y};   
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