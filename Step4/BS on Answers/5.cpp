#include<bits/stdc++.h>
using namespace std;

long long divisor(vector<int> &nums,int div)
{
    int n = nums.size();
    long long sum = 0; 
    for(int i = 0; i<n; i++)
    {
        sum += ceil((double)nums[i]/div);
        // sum += (nums[i] + div - 1) / div; // fastest way to solve ceil 
    }
    return sum;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    if(n>threshold) return -1;
    int s = 1, e = *max_element(nums.begin(), nums.end());;
    int ans = -1;
    long long divSum = 0;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        divSum = divisor(nums,mid);
        if(divSum<=threshold)
        {
            ans = mid;
            e = mid-1;
        }
        else 
        {
            s=mid+1;
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
    cout << smallestDivisor(piles,m);
    return 0;
}