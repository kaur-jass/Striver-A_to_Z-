#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        vector<int> temp;
        for(int i= 0; i<n; i++)
        {
            hash[nums[i]]++;
        }
        for(auto it:hash)
        {
            if(it.second>n/3) temp.push_back(it.first);
        }
        return temp;
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