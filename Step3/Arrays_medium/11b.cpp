#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix)
{
    
    int m = matrix.size();
    int n = matrix[0].size();
    int row[m] = {0};
    int col[n] = {0};
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1; // Marking the row
                col[j] = 1; // Marking the column
            }
        }
    }
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0; // Setting the cell to zero
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
