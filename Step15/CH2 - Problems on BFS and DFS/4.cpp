#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(); 
        int n = image[0].size(); 
        int original = image[sr][sc];
        if(original == color) return image;  // important edge case

        queue<pair<int, int>> q; 
        q.push({sr, sc}); 
        image[sr][sc] = color;  // color start

        while(!q.empty()){
            int size = q.size();  
            for(int i = 0; i<size; i++){
                int r = q.front().first;
                int c = q.front().second; 
                q.pop();
                if(r-1 >= 0 && image[r-1][c] == original){
                    image[r-1][c] = color; 
                    q.push({r-1,c}); 
                }
                if(r+1 < m && image[r+1][c] == original){
                    image[r+1][c] = color; 
                    q.push({r+1,c}); 
                }
                if(c-1 >= 0 && image[r][c-1] == original){
                    image[r][c-1] = color; 
                    q.push({r,c-1}); 
                }
                if(c+1 < n && image[r][c+1] == original){
                    image[r][c+1] = color; 
                    q.push({r,c+1});
                }
            } 
        }
        return image;
    }
};

int main(){
    Solution s;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = s.floodFill(image, sr, sc, color);
    
    for(const auto& row : result) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}