#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(); 
        if(n == 0) return {newInterval}; 
        int i = 0;
        vector<vector<int>> ans;
        while(i<n && intervals[i][1]<newInterval[0]){ // No Overlapping
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        } 
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++; 
        }
        ans.push_back(newInterval); 
        while(i<n){ // now the rest are always non overlapping 1
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++; 
        }
        return ans; 
    }
};
int main(){
    Solution s; 
    vector<vector<int>> intervals = {{1,3}, {6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    for(auto i: ans){
        cout<<"["<<i[0]<<","<<i[1]<<"] ";
    }
    return 0;
}