#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int it : nums1){
            for(int jt : nums2){
                minheap.push(it + jt); 
                if(minheap.size() > k) minheap.pop();
            }
        }
        vector<int> result;
        while(!minheap.empty()) {
            result.push_back(minheap.top());
            minheap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
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