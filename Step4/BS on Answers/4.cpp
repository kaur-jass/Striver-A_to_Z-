#include<bits/stdc++.h>
using namespace std;

int smallest(vector<int>& nums)
{
    int n = nums.size();
    int maxx = nums[0];
    for(int i = 0; i < n; i++)
    {
        if (maxx > nums[i])
        {
            maxx = nums[i];
        }
    }
    return maxx;
}
int largest(vector<int>& nums)
{
    int n = nums.size();
    int maxx = nums[0];
    for(int i = 0; i < n; i++)
    {
        if (maxx < nums[i])
        {
            maxx = nums[i];
        }
    }
    return maxx;
}
bool bloom(vector<int>& bloomDay, int k, int ans,int m)
{
    int n = bloomDay.size();
    int flower = 0; 
    int bouquet = 0;
    for(int i= 0; i<n;i++)
    {
        if(bloomDay[i] <=ans)
        {
            flower += 1;
            if (flower == k)
            {
                bouquet += 1; 
                flower = 0;
            }
        }
        else
        {
            flower = 0;
        }
    }
if(bouquet >= m) return true; 
    return false;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    long long n = bloomDay.size();
    long long val = 1LL * m * 1LL * k;
    if(val>n) return -1;
    int ans = 0;
    int e = largest(bloomDay);
    int s = smallest(bloomDay);
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if(bloom(bloomDay,k,mid,m))
        {
            ans = mid; 
            e = mid-1;
        }
        else
        {
            s= mid+1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n; 
    vector<int> piles(n);
    for(int i = 0; i<n; i++)
    {
        cin >> piles[i];
    }
    int m; 
    cin >> m;
    int k;
    cin >> k;
    cout << minDays(piles,m,k);
    return 0;
}