#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> result;
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                result.push_back(nums1[i] + nums2[j]);
            }
        }
        sort(result.begin(), result.end(), greater<int>());
        vector<int> topK(result.begin(), result.begin() + min(k, (int)result.size()));
        return topK;
    }
};
int main() {
    Solution obj;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = obj.maxCombinations(nums1, nums2, k);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}