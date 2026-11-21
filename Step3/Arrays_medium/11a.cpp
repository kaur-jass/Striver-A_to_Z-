#include<bits/stdc++.h>
using namespace std;

void mark_row(vector<vector<int>>& matrix, int row)
{
    int n = matrix[0].size();
    for(int j=0; j<n; j++)
    { 
        if(matrix[row][j] != 0)
        {
            matrix[row][j] = -1; // Marking with -1 to avoid confusion with 0
        }
    }
}
void mark_col(vector<vector<int>>& matrix, int col)
{
    int m = matrix.size();
    for(int i=0; i<m; i++)
    { 
        if(matrix[i][col] != 0)
        {
            matrix[i][col] = -1; // Marking with -1 to avoid confusion with 0
        }
    }
}
void setZeroes(vector<vector<int>>& matrix)
{
    
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n;j++)
        {
            if(matrix[i][j] == 0)
            {
                mark_row(matrix, i);
                mark_col(matrix, j);
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n;j++)
        {
            if(matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    
}
int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows,vector<int>(cols));
    for(int i = 0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    setZeroes(matrix);
    for(int i = 0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
