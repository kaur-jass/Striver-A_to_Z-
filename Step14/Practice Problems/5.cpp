#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &inodr){
        if(root == NULL) return; 
        inorder(root->left, inodr);
        inodr.push_back(root->val); 
        inorder(root->right, inodr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inodr; 
        inorder(root, inodr);  // inorder always gives sorted values
        return inodr[k-1]; 
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution sol;
    int k = 1;
    int kthSmallestValue = sol.kthSmallest(root, k);
    
    cout << "The " << k << "st smallest element in the BST is: " << kthSmallestValue << endl;

    return 0;
}