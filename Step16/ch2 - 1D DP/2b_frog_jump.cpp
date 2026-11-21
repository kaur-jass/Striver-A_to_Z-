#include<bits/stdc++.h>
using namespace std;

class Solution{                  // space optimization solution 
public: 
    int frogJump(int n, vector<int> &heights) {
        int prev = 0; 
        int prev2 = 0; 
        for(int i = 1; i<n; i++){
            int fs = prev + abs(heights[i] - heights[i-1]); 
            int ss = INT_MAX; 
            if(i>1) ss = prev2 + abs(heights[i] - heights[i-2]); 
            int curr = min(fs, ss); 
            prev2 = prev;
            prev = curr; 
        }
        return prev; 
    }
}; 

int main(){
    cout << "Enter the number of steps: ";
    int n;
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the heights of the steps: ";
    for(int i = 0; i < n; i++) cin >> heights[i];
    Solution obj;
    cout << "The minimum energy required to reach the nth step is : " << obj.frogJump(n-1, heights) << endl;
    return 0;
} 