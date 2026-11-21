#include<bits/stdc++.h>
using namespace std; 

class Solution {
    void solve(int i, int j,
               vector<vector<int>> &a, int n,
               vector<string> &ans,
               string move,
               vector<vector<int>> &vis,
               int di[], int dj[]) {

        // Base case: reached destination
        if (i == n-1 && j == n-1) {
            ans.push_back(move);
            return;
        }

        string dir = "DLRU";  // order of directions

        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            // Check boundaries + unvisited + open cell
            if (nexti >= 0 && nextj >= 0 &&
                nexti < n && nextj < n &&
                !vis[nexti][nextj] &&
                a[nexti][nextj] == 1) {

                vis[i][j] = 1;                 // mark visited
                solve(nexti, nextj, a, n,
                      ans, move + dir[ind],
                      vis, di, dj);
                vis[i][j] = 0;                 // backtrack
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // direction arrays (DLRU)
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, +1, 0};

        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis, di, dj);

        return ans;
    }
};


int main(){
     vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = maze.size();
    Solution obj;
    vector<string> paths = obj.findPath(maze, n);
    for (auto &p : paths) cout << p << " ";
}