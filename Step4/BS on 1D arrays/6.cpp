#include<bits/stdc++.h>
using namespace std;
// Brute Force Approach.....
vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
       vector<int> temp;
       for(int i=0; i<n; i++)
       {
            if(nums[i] == target) 
            {
                temp.push_back(i);
                break;
            }
       }
       for(int j= n-1; j>=0; j--)
       {
            if(nums[j] == target) 
            {
                temp.push_back(j);
                break;
            }
       }
       if (temp.size() == 2) return temp;
       return {-1,-1};
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> temp = searchRange(a,k);
    for(int i = 0; i<n; i++)
    {
        cout << temp[i] << " ";
    }
    return 0;

}
