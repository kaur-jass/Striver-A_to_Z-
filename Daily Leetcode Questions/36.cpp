#include<bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
    int m = board.size(); 
    int n = board[0].size(); 
    bool flag = true; 
    for(int i = 0; i<m; i++)
    {
        map<char,int> mpp; 
        for(int j = 0; j<n; j++)
        {
            if(board[i][j] == '.') continue;
            else if(mpp[board[i][j]] == 1)
            {
                flag= false; 
                break; 
            } 
            mpp[board[i][j]]++; 
        }
        if(flag == false) return flag; 
    }
    for(int i = 0; i<n; i++)
    {
        map<char,int> mpp; 
        for(int j = 0; j<m; j++)
        {
            if(board[j][i] == '.') continue;
            else if(mpp[board[j][i]] == 1)
            {
                flag= false; 
                break; 
            } 
            mpp[board[j][i]]++; 
        }
        if(flag == false) return flag; 
    }
    for(int boxRow = 0; boxRow<3; boxRow++)
    {
        for(int boxCol = 0; boxCol<3; boxCol++)
        {
            map<char,int> mpp; 
            for(int i = 0; i<3; i++)
            {
                for(int j = 0; j<3; j++)
                {
                    char c = board[boxRow*3+i][boxCol*3+j];
                    if(c == '.') continue; 
                    else if(mpp[c] == 1)
                    {
                        flag = false; 
                        return flag;
                    }
                    mpp[c]++;
                }
            }
        }
    }
    return flag;     
}
int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    bool result = isValidSudoku(board);
    cout << (result ? "true" : "false") << endl;

    return 0;
}