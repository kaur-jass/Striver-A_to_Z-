#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort the array using brute force
    vector<int> sortNearlySortedArray(vector<int>& arr, int k) {
        // Sort the entire array
        sort(arr.begin(), arr.end());

        // Return the sorted array
        return arr;
    }
};

// Your brute force solution works because:
// Sorting ignores distance.
// Sorting guarantees final correct order.
// k-sorted property is only for optimization, not correctness.

// Driver code
int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    Solution obj;
    vector<int> result = obj.sortNearlySortedArray(arr, k);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}

