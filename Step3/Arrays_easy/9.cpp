#include<bits/stdc++.h>
using namespace std;

vector<int> uni(vector<int> &a, vector<int> &b)
{
      int n1 = a.size();
      int n2 = b.size();
      int i = 0;
      int j = 0;
      vector<int> unionarr;
      while(i<n1 && j<n2)
      {
         if(a[i]<b[j]){
            if(unionarr.size() == 0 || unionarr.back() != a[i]) unionarr.push_back(a[i]);
            i++;
         }
         
         else{
            if(unionarr.size() == 0 || unionarr.back() != b[j]) unionarr.push_back(b[j]);
            j++;
         }  
      }
      while(i<n1)
      {
         if(unionarr.size() == 0 || unionarr.back() != a[i]) unionarr.push_back(a[i]);
         i++;
      }
      while(j<n2)
      {
         if(unionarr.size() == 0 || unionarr.back() != b[j]) unionarr.push_back(b[j]);
         j++;
      }
      return unionarr;
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

    
