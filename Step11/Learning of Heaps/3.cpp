// Problem Statement: Given an array of integers nums. Check whether the array represents a binary min-heap or not. 
// Return true if it does, otherwise return false.
// A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys 
// present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.



#include<bits/stdc++.h>
using namespace std; 

bool isMinHeap(vector<int>& nums) {
    int n = nums.size();

    // Only non-leaf nodes
    for(int i = 0; i <= (n/2) - 1; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && nums[i] > nums[left])
            return false;

        if(right < n && nums[i] > nums[right])
            return false;
    }
    return true;
}
int main() {
    vector<int> nums = {10, 20, 30, 21, 23}; 
    bool ans = isMinHeap(nums); 

    if(ans) 
        cout << "The array represents Min Heap" << endl; 
    else
        cout << "The array does not represent Min Heap" << endl; 

    return 0;
}