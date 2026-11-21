#include<bits/stdc++.h>
using namespace std; 
class Solution{
    public:
        void solve(int i, int j,vector<vector<int>>& maze, int n, vector<string>& ans, string& st){
            if(maze[i][j] == 0) return;
            if(i == n-1 && j == n-1){
                ans.push_back(st);     
                return; 
            }

             
            maze[i][j] = 0; 
            if(i+1 < n && maze[i+1][j] == 1){
                st.push_back('D');
                solve(i+1, j, maze, n, ans, st);
                st.pop_back();
            }
            if(j+1 <n && maze[i][j+1] == 1){
                st.push_back('R');
                solve(i, j+1, maze, n, ans, st);
                st.pop_back();
            }
            if(i>0 &&maze[i-1][j] == 1){
                st.push_back('U');
                solve(i-1, j, maze, n, ans, st);
                st.pop_back();
            }
            if(j > 0 && maze[i][j-1] == 1){
                st.push_back('L');
                solve(i, j-1, maze, n, ans, st);
                st.pop_back();
            }
            maze[i][j] = 1; 
        }
        vector<string> findPath(vector<vector<int>>& maze, int n){
            vector<string> ans;
            if(maze[0][0] == 0) return ans; 
            string st = "";
            solve(0, 0, maze, n, ans, st); 
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