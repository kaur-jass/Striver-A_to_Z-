#include<bits/stdc++.h>
using namespace std;

vector<int> maximum_no_of_ones(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxione = 0;
    int maxirow = 0;
    for(int i = 0; i<n ;i++)
    {
        int cnt = 0;
        for(int j = 0; j<m; j++)
        {
            if(mat[i][j] == 1) cnt++;
        }
        if(cnt>maxione ||(maxione == cnt && i<maxirow))
        {
            maxirow = i;
            maxione = cnt;
        }
    }
    return {maxirow,maxione};
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