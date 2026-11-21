#include<bits/stdc++.h>
using namespace std;

vector<int> maximum_no_of_ones(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int result = 0;
    int ans = 0;
    vector<int> maxione;
    unordered_map<int, int> map;
    for(int i = 0; i<n ;i++)
    {
        int cnt = 0;
        for(int j = 0; j<m; j++)
        {
            if(mat[i][j] == 1) cnt++;
        }
        map[i] = cnt;
    }
    for(auto it : map)
    {
        if(it.second > result || (it.second == result && it.first < ans))  // u need to check that if same no of ones present then return row with smaller index......
        {
            result = it.second;
            ans = it.first;
        }
    }
    maxione.push_back(ans);
    maxione.push_back(result);
    return maxione;
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
    vector <int> result = maximum_no_of_ones(matrix);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}