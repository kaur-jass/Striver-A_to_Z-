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
    bool flag = false; 
    int low = 0, high = matrix.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if (target >= matrix[mid][0] && target <= matrix[mid].back()) {
            flag = searchinrow(matrix[mid], target);
            return flag;
        }
        else if(target < matrix[mid][0])
        {
            high = mid-1;
        }
        else
        {
            low= mid+1;
        }
    }
    return flag;
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