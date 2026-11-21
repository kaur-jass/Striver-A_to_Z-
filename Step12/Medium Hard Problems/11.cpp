#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(); 
        int cnt = 0; 
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];   // sort by end
        });
        int end = intervals[0][1]; 
        for(int i = 1; i<n; i++){
            if(end > intervals[i][0]) cnt++; 
            else end = intervals[i][1];
        }
        return cnt;
    }
};
int main(){
    Solution s; 
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    cout<<s.eraseOverlapIntervals(intervals)<<endl; 
    return 0;
}