#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix)
{
    
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if(j != 0) {
                    matrix[0][j] = 0; // Marking the first row and column
                } else {
                    col0 = 0; // If the first column has a zero, we need to handle it later
                }    
            }     
        }
    }
    for(int i = 1; i<m; i++)
    {
        for(int j = 1; j<n; j++)
        {
            if(matrix[i][j] != 0)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0; // Setting the cell to zero
                }
            }
        }
    }
    if(matrix[0][0] == 0)
    {
        for(int j = 0; j<n; j++)
        {
            matrix[0][j] = 0; // Setting the first row to zero
        }
    }
    if(col0 == 0)
    {
        for(int i = 0; i<m; i++)
        {
            matrix[i][0] = 0; // Setting the first column to zero
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
