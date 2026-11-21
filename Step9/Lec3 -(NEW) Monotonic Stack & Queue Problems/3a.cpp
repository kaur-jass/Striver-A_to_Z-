#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //Strivers soln 
        vector<int> st;  // Now in this implementation, we are using a vector as a stack to store the asteroids that are still alive after collisions.
        for(int asteroid : asteroids){ // don't immediately push asteroid into the stack; 
           if(asteroid > 0) {
                st.push_back(asteroid); // If the asteroid is moving to the right, we can safely add it to the stack.
            } else {
                while(!st.empty() && st.back() > 0 && st.back() < abs(asteroid)) {
                    st.pop_back(); // If the top of the stack is a smaller asteroid moving to the right, it will be destroyed.
                }
                if(st.empty() || st.back() < 0) {
                    st.push_back(asteroid); // If the stack is empty or the top of the stack is a left-moving asteroid, we can add the current asteroid.
                } else if(st.back() == abs(asteroid)) {
                    st.pop_back(); // If they are equal, both asteroids destroy each other.
                }
            }
        }        
        return st; 
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