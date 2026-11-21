#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
     vector<int> ls;
     int n = nums.size();
     for(int i = 0; i <n ; i++)
     {
        if(ls.size() == 0 || ls[0] != nums[i])
        {
            int cnt = 0;
            for(int j = 0; j<n; j++)
            {
                if(nums[i] == nums[j]) cnt++;
            }
            if(cnt > n/3) ls.push_back(nums[i]);
            if(ls.size() == 2) break;
        }
     }
     return ls;
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
    vector<int> temp = majorityElement(a);
    for(int i = 0; i<n; i++)
    {
        cout << temp[i] << " ";
    }
    return 0;

}