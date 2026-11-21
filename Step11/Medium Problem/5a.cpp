#include<bits/stdc++.h>
using namespace std;

vector<int> rankdata(const vector<int>& nums){
    int n = nums.size(); 
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int i=0; i<n; i++){
        minheap.push(nums[i]); 
    }
    unordered_map<int, int> rankMap;
    int rank = 1;
    // Store only unique elements in ranks
    while(!minheap.empty()){
        int curr = minheap.top();
        minheap.pop(); 
        if(rankMap.find(curr) == rankMap.end()){
            rankMap[curr] = rank++;
        }
    }      
    vector<int> finalRanks;
    for(int i=0; i<n; i++){
        finalRanks.push_back(rankMap[nums[i]]);
    }
    return finalRanks;
}
int main(){
    // Input: 20 15 26 2 98 6
    // Output: 4 3 5 1 6 2
    // Explanation: When sorted,the array is 2,6,15,20,26,98. So the rank of 2 is 1,rank of 6 is 2,rank of 15 is 3 and so.
    vector<int> nums = {20,15,26,2,98,6,15,26,2};
    vector<int> ans = rankdata(nums);
    cout << "[";
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout << "]\n";
    return 0;
}