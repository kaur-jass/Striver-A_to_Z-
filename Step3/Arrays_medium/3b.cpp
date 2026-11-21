#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums)
{
    int n= nums.size();
    int cnt = 0;
    int el;
    for(int i = 0; i < n; i++)
    {
        if(cnt == 0)
        {
            cnt = 1;
            el = nums [i];
        }
        else if (nums[i] == el) cnt++;
        else cnt--;
    }
    int cnt1 = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == el) cnt1++;
    }
    if(cnt1 > n/2) return el;
    return -1; // This line is just a fallback, ideally we should not reach here if the input guarantees a majority element.
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << majorityElement(nums) << endl;
    return 0;
}