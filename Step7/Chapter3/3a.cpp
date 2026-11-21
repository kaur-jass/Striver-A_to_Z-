#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int col,vector<string>& board,vector<vector<string>>& ans,vector<int>& leftRow, vector<int>& UpperDiagonal, vector<int>& LowerDiagonal, int n){
        if(col == n){
            ans.push_back(board); 
            return; 
        }
        for(int row = 0; row<n; row++){
            if(leftRow[row] == 0 && LowerDiagonal[row+col] == 0 && UpperDiagonal[n-1 + col-row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1; 
                LowerDiagonal[row+col] = 1; 
                UpperDiagonal[n-1 + col-row] = 1; 
                solve(col+1, board, ans,leftRow,UpperDiagonal,LowerDiagonal, n); 
                board[row][col] = '.'; 
                leftRow[row] = 0; 
                LowerDiagonal[row+col] = 0; 
                UpperDiagonal[n-1 + col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n); 
        string s(n, '.');
        for(int i = 0; i<n; i++){
            board[i]= s; 
        }
        vector<int> leftRow(n, 0), UpperDiagonal(2*n-1,0), LowerDiagonal(2*n-1, 0); 
        solve(0, board, ans,leftRow,UpperDiagonal,LowerDiagonal, n); 
        return ans; 
    }
};


int main(){
    Solution sol; 
    int n = 4; 
    vector<vector<string>> ans = sol.solveNQueens(n); 
    for(auto board: ans){
        for(auto row: board){
            cout<<row<<endl; 
        }
        cout<<endl; 
    }
    return 0;
}