#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(vector<vector<int> > &intervals) 
{
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

int main()
{
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> g[i][j];
        }
    }
    vector<vector<int>> intervals =  graph(g);
    for(int i = 0; i<intervals.size(); i++)
    {
        for(int j = 0; j<intervals[i].size(); j++)
        {
            cout << intervals[i][j];
        }
    }
    return 0;


}