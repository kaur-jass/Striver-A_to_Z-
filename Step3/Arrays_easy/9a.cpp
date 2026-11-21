#include<bits/stdc++.h>
using namespace std;

vector<int> uni(vector<int> &nums1, vector<int> &nums2)
{
   int n1 = nums1.size();
   int n2 = nums2.size();
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}

int main()
{
    int x;
    cin >> x;
    vector<int> nums1;
    for(int i = 0; i<x; i++)
    {
        int val;
        cin >> val;
        nums1.push_back(val);
    }
    int y;
    cin >> y;
    vector<int> nums2;
    for(int i = 0; i<y; i++)
    {
        int val;
        cin >> val;
        nums2.push_back(val);
    }
    vector<int> ans = uni(nums1,nums2);
    for(int i = 0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}