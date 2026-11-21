#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col , int num){
        for(int i = 0; i<9; i++){
            if(num == board[row][i]) return false;
            if(num == board[i][col]) return false;  
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if(board[i][j] == num)
                    return false;
            }
        }
        return true; 
    }
    bool solve(vector<vector<char>>& board){
        int row = 0; 
        int col = 0; 
        bool found = false;
        for(int i = 0; i<9 && !found; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.'){
                    row = i; 
                    col = j;
                    found = true;  
                    break; 
                } 
            }
        }
        // Base Case
        if(!found) return true; 
        for(char i = '1'; i<='9'; i++){
            if(isSafe(board, row, col, i)){
                board[row][col] = i;
                if(solve(board)) return true; 
                board[row][col] = '.';
            }
        }
        return false; 
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); 
    }
};
int main() {
    // Initialize the Sudoku board with given values and '.' for blanks
    vector<vector<char>> board {
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };


    Solution sol;
    sol.solveSudoku(board);

    // Print the solved Sudoku board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}