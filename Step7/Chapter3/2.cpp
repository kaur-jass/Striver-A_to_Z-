#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool generate(int index, int i, int j, string word, vector<vector<char>>& board){
        int m = board.size(); 
        int n = board[0].size();
        if(index == word.length()){
            return true; 
        } 
        char s = word[index]; 
        bool flag = false; 
        char temp = board[i][j]; 
        board[i][j] = '#';
        if(j<n-1 && board[i][j+1] == s){ 
            flag = generate(index+1, i, j+1, word, board);
            if (flag) return true; 
        }
        if(j>0 && board[i][j-1] == s){
            flag = generate(index+1, i, j-1, word, board);
            if (flag) return true;
        }
        if(i<m-1 && board[i+1][j] == s){
            flag = generate(index+1, i+1, j, word, board); 
            if (flag) return true;
        }
        if(i>0 && board[i-1][j] == s){
            flag = generate(index+1, i-1, j, word, board);
            if (flag) return true;
        }
        board[i][j] = temp; 
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(); 
        int n = board[0].size();
        string st = "";
        char s = word[0];
        bool flag = false; 
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(s == board[i][j]){
                    flag = generate(1, i, j, word, board); 
                    if(flag) return true; 
                }
            }
        }  
        return flag;               
    }
};
int main(){
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    Solution sol; 
    bool ans = sol.exist(board, word); 
    if(ans){
        cout<<"Word exists in the board"<<endl; 
    } else {
        cout<<"Word does not exist in the board"<<endl; 
    }
    return 0; 
}