#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(vector<vector<int> > &arr) 
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans; 
    for(int i = 0; i<n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1]; 
        if(!ans.empty() && end <= ans.back()[1]) continue;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else break; 
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main()
{
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<vector<int>> g(m, vector<int>(n));
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