#include<bits/stdc++.h>
using namespace std;
int sequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    int min = *min_element(nums.begin(), nums.end());
    ans.push_back(min);
    min = min+1;
    while(find(nums.begin(), nums.end(), min) != nums.end()) {
        for(int i = 0; i <n; i++)
        {
            if(nums[i] == min) {
                ans.push_back(nums[i]);
                min++;
                break;
            }
        }
    }
    return ans.size();
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << sequence(nums) << endl;
    return 0;
}