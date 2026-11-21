#include<bits/stdc++.h>
using namespace std;

int el_left(vector<int> &cows,int m,int k) 
{
    int n = cows.size();
    k = k-1; // As the first aggresive cow is at index 0
    int i = 0;
    for(int j = 0; j<n; j++)
    {
        if(cows[i]+m <= cows[j])
        {
            i = j;
            k--;
        }
    }
    return k;
}

int aggresive_cows(vector<int> &cows, int k)
{
    sort(cows.begin(), cows.end());
    int n = cows.size();
    int s = 1, e = cows[n-1] - cows[0];
    int ans = 0;
    while(s<=e)
    {
        int m = s+(e-s)/2;
        if (el_left(cows,m,k) <= 0)
        {
            ans = m;
            s = m+1;
        }
        else e = m-1;
    }
    return ans;
}


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i]; 
    }
    int k; 
    cin >> k;
    int ans = aggresive_cows(nums, k);
    cout << ans << endl;
    return 0;
}