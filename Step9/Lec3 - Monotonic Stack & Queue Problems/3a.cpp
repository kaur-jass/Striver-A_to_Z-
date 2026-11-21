#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to find the next smaller 
    element for each element in the array */
    vector<int> nextSmallerElement(vector<int>& arr) {
        
        int n = arr.size(); // size of array
        
        // To store the next smaller elements
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; ++i) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Nested loop to get the 
            next smaller element */
            for (int j = i + 1; j < n; ++j) {
                
                // If the next smaller element is found
                if (arr[j] < currEle) {
                    
                    // Store the next smaller element
                    ans[i] = arr[j];
                    
                    // Break from the loop
                    break;
                }
            }
        }
        
        // Return the answer
        return ans;
    }
};

int main() {
    int n = 5;
    vector<int> arr = {4, 8, 5, 2, 25};

    /* Creating an instance of 
    Solution class */
    Solution sol;
    
    /* Function call to find the next smaller element
    for each element in the array */
    vector<int> ans = sol.nextSmallerElement(arr);
    
    cout << "The next smaller elements are: ";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}