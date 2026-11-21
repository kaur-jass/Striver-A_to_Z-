#include<bits/stdc++.h>
using namespace std; 

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0;
    int col = matrix[0].size()-1;
    while(row <matrix.size() && col>=0)
    {
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) col--;
        else row++;
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