#include<bits/stdc++.h>
using namespace std; 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i =0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == target) return true;
            }
        }
    return false;
}
int main()
{
    int n; 
    cin >> n; 
    int m;
    cin >> m; 
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i =0; i<n ; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int target; 
    cin >> target; 
    cout << searchMatrix(matrix, target) ? "true" : "false";
}