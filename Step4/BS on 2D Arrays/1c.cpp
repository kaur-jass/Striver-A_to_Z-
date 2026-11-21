#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector <int> &arr, int x)
{
    int n = arr.size();
    int low = 0, high = arr.size() - 1;
    while (low <= high) {   
        int mid = low + (high - low) / 2;
        if (arr[mid] < x)
        low = mid + 1;
        else
        high = mid - 1;
    }    
    return low;
}
int maximum_no_of_ones(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxione = 0;
    int maxirow = -1;
    int cnt = 0; 
    for(int i = 0; i<n ; i++)
    {
       // TC = O(n * log2(m))
       cnt = m-lower_bound(matrix[i],1);
       if(cnt>maxione)
       {
            maxione = cnt;
            maxirow = i;
       }
    }
    return maxirow;
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
    cout << maximum_no_of_ones(matrix);
    return 0;
}