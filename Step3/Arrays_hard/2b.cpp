#include<bits/stdc++.h>
using namespace std;


vector<int> majorityElement(vector<int>& nums)
{
    int n = nums.size();
    int count1 = 0, count2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for(int i = 0; i<n; i++)
    {
        if (count1 == 0 && nums[i] != el2)
        {
            count1 = 1;
            el1 = nums[i];
        }
        else if(count2 == 0 && nums[i] != el1)
        {
            count2 = 1;
            el2 = nums[i];
        }
        else if(nums[i] == el1) count1++;
        else if(nums[i] == el2) count2++;
        else count1--,count2--;
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i<n; i++)
    {
        if(nums[i] == el1) cnt1++;
        else if(nums[i] == el2) cnt2++;
    }
    vector<int> ls;
    if(cnt1 > n/3) ls.push_back(el1);
    if(cnt2 > n/3) ls.push_back(el2);
    sort(ls.begin(),ls.end());
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