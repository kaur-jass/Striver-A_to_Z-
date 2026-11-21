#include<bits/stdc++.h>
using namespace std;

// define tree node structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &nums){
        if(root == NULL) return;
        inorder(root->left, nums);
        nums.push_back(root->val); 
        inorder(root->right, nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums; 
        inorder(root, nums); 
        // unordered_map<int, int> mpp;
        // int n = nums.size();
        // for(int i = 0; i < n; i++) 
        // {
        //     int num = nums[i];
        //     int moreneeded = k - num;
        //     if(mpp.find(moreneeded) != mpp.end())
        //     {
        //         return true;
        //     }
        //     mpp[num] = i;
        // }
        // return false;
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int sum = nums[left] + nums[right];

            if(sum == k) return true;
            else if(sum < k) left++;
            else right--;
        }
        return false;
    }
};

int main(){
    // construct BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    int k = 9;
    Solution s;
    bool ans = s.findTarget(root, k);
    if(ans) cout << "Found a pair with sum " << k << endl;
    else cout << "No pair with sum " << k << " found." << endl;
    return 0;
}