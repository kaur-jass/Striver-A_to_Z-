#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1) return intervals;
        vector<pair<int,int>> interval;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (merged.back()[1] >= intervals[i][0]) {
                // Overlap — merge by updating the end
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } 
            else {
                // No overlap — just push
                merged.push_back(intervals[i]);
            }
        }
        return merged;  
    }
};
int main(){
    Solution s; 
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> ans = s.merge(intervals);
    for(auto i: ans){
        cout<<"["<<i[0]<<","<<i[1]<<"] ";
    }
    return 0;
}