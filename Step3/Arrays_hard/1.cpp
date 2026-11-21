#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {

    vector<vector<int>> ps;
    for(int i =0; i<numRows;i++)
    {
        vector<int> rows;
        int res = 1;
        for(int j = 0; j<=i;j++)
        {
            rows.push_back(res);
            res = res * (i - j) / (j + 1);
        }
        ps.push_back(rows);
    }
    return ps;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ps = generate(n);
    for(int i= 0;i<n; i++)
    {
        for(int j=0; j<=i;j++)
        {
            cout << ps[i][j] <<" ";
        }
    }
    return 0;
}