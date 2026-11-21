#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort the array using brute force
    vector<int> sortNearlySortedArray(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> sortedArr;
        for(int i = 0; i < arr.size(); i++) {
            minHeap.push(arr[i]);
            if(minHeap.size() > k) {
                sortedArr.push_back(minHeap.top());
                minHeap.pop();
            }
        }
        while(!minHeap.empty()) {
            sortedArr.push_back(minHeap.top());
            minHeap.pop();
        }
        return sortedArr;
    }
};

// Your brute force solution works because:
// Sorting ignores distance.
// Sorting guarantees final correct order.
// k-sorted property is only for optimization, not correctness.

// Driver code
int main() {
    vector<int> arr = {1, 4, 5, 2, 3, 6, 7, 8, 9, 10};
    int k = 2;
    Solution obj;
    vector<int> result = obj.sortNearlySortedArray(arr, k);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}

