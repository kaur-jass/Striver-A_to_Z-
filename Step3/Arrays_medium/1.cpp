#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> temp;
    for(int i = 0; i<= n-1;i++)
    {
        for(int j = i+1; j <= n-1; j++)
        {
            if(nums[i] + nums[j] == target) 
            {
                temp.push_back(i);
                temp.push_back(j);
            }
        }
    }
    return temp;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "[]" << endl;
    }

}