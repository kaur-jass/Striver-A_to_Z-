#include<bits/stdc++.h>
using namespace std;
vector<int> repeating_and_missing(vector<int> &a)
{
    long long n = a.size();
    int xr = 0;
    for(int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i+1);
    }
    int bitno = 0; 
    while(1){
        if((xr&(1<<bitno)) != 0) break;
        bitno++;
    }
    int zero = 0; 
    int one = 0; 
    for(int i = 0; i < n; i++)
    {
        // Part of 1 Club 
        if((a[i] &(1<<bitno)) != 0) one = one^a[i];
        // Part of 0 Club
        else zero = zero^a[i];
    }
    int cnt= 0; 
    for(int i = 0; i < n; i++)
    {
        if(a[i] == zero) cnt++;
    }
    if(cnt == 2) return {zero, one};
    return {one, zero};
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