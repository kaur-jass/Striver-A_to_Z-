#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> temp;
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = m-1;
        while(temp.size()< m*n)
        {
            for(int i=left; i<=right && temp.size() < m * n;i++)
            {
                temp.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<=bottom && temp.size() < m * n; i++)
            {
                temp.push_back(matrix[i][right]);
            }
            right--;
            for(int i=right; i>=left && temp.size() < m * n; i--)
            {
                temp.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i=bottom; i>=top && temp.size() < m * n; i--)
            {
                temp.push_back(matrix[i][left]);
            }
            left++;
        }
        return temp;
}

int main()
{
    
}