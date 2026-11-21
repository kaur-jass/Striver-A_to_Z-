#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    int maxi = nums[0];
    for(int i = 0; i<n; i++)
    {
        int  k = 1;
        for (int j = i; j<n;j++)
        {
            k = k*nums[j];
            maxi = max(maxi,k);
            if(k == 0) break;
        }
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