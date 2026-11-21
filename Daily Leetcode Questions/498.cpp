#include<bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(); 
        int n = mat[0].size(); 
        int r = 0; 
        int c = 0; 
        vector<int> ans; 
        for(int i = 0; i<m*n; i++)
        {
            ans.push_back(mat[r][c]);
            int sum = r+c;
            if(sum%2 != 0)
            {
                if(c == 0 && r != m-1) r++; 
                else if (r == m-1) c++;
                else{
                    r++, c--;
                }
            }
            if(sum%2 == 0)
            {
                if(c == n-1) r++; 
                else if (r == 0 && c != n-1) c++;
                else{
                    r--, c++;
                }
            }
        }
        return ans; 
}


int main() {
    // Example input
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the function
    vector<int> result = findDiagonalOrder(mat);

    // Print the output
    cout << "[ ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << "]" << endl;

    return 0;
}