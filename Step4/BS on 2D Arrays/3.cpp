#include<bits/stdc++.h>
using namespace std; 

bool searchinrow(vector<int>& arr, int target)
{
    int low = 0, high = arr.size()-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == target) return true; 
        else if(arr[mid]< target) 
        {
            low = mid+1; 
        }
        else
        { 
            high = mid-1;
        }
    }
    return false;  
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n  = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i<n; i++)
    {
        if(searchinrow(matrix[i], target))
        return true;
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