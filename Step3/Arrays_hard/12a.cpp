#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    int prefix = 1;
    int suffix = 1; 
    for(int i = 0; i <n; i++)
    {
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[n-1-i];
        maxi = max(maxi,max(prefix, suffix));
    }
    return maxi;
}

int main()
{
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i<n; i++)
    {
        cin >> v[i];
    }
    cout << maxProduct(v) << endl;
}