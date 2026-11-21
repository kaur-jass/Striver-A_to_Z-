#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int r, int c, int n, int m,  vector<vector<char>>& board){
        // vis[r][c] = 1; 
        board[r][c] = '#'; 
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int k = 0; k<4; k++){
            int nr = r + dr[k]; 
            int nc = c + dc[k]; 
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc] == 'O'){
                dfs(nr, nc, n, m, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(); 
        int m = board[0].size(); 
        // vector<vector<int>> vis(n, vector<int>(m, 0)); 
        for(int i = 0; i<n; i++){
            if(board[i][0] == 'O') dfs(i, 0, n, m, board);  
            if(board[i][m-1] == 'O') dfs(i, m-1, n, m, board);  
        }
        for(int j = 0; j<m; j++){
            if(board[0][j] == 'O')  dfs(0, j, n, m, board);   
            if(board[n-1][j] == 'O')  dfs(n-1, j, n, m, board);   
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X'; 
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == '#') board[i][j] = 'O'; 
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {{'X','X','X','X'},
                                  {'X','O','O','X'},
                                  {'X','X','O','X'},
                                  {'X','O','X','X'}};
    Solution sol;
    sol.solve(board);
    for (const auto& row : board) {
        for (char x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}