#include<bits/stdc++.h>
using namespace std;

int maximum_no_of_ones(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int result = 0;
    int ans = -1;
    unordered_map<int, int> map;
    for(int i = 0; i<n ;i++)
    {
        int cnt = 0;
        for(int j = 0; j<m; j++)
        {
            if(matrix[i][j] == 1) cnt++;
        }
        map[i] = cnt;
    }
    for(auto it : map)
    {
        if(it.second > result) 
        {
            result = it.second;
            ans = it.first;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n; 
    int m; 
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << maximum_no_of_ones(matrix);
    return 0;
}