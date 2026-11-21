#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; 
        vector<int> ans; 
        for(int asteroid : asteroids){ // don't immediately push asteroid into the stack; 
            bool alive = true;  
            while (!st.empty() && st.top() > 0 && asteroid < 0){
                if(abs(asteroid) < st.top()){
                    alive = false; 
                    break; 
                }
                else if(abs(asteroid) > st.top()){
                    st.pop(); 
                }
                else{
                    st.pop(); 
                    alive = false; 
                    break; 
                }
            }
            if(alive) st.push(asteroid); 
        }
        while(!st.empty()){
            ans.push_back(st.top()); 
            st.pop(); 
        }
        reverse(ans.begin(), ans.end()); 
        return ans; 
    }
}; 

int main()
{
    int n; 
    cin >> n; 
    vector<int> asteroids(n); 
    for(int i = 0; i<n; i++) cin >> asteroids[i]; 
    Solution sol; 
    vector<int> ans = sol.asteroidCollision(asteroids); 
    for(auto x : ans) cout << x << " "; 
    cout << "\n"; 
    return 0; 
}