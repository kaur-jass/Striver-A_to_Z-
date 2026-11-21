#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* prev = NULL; 
    void flatten(TreeNode* root) {
        if(!root) return; 
        flatten(root->right); 
        flatten(root->left); 
        root->right = prev; 
        root->left = NULL; 
        prev = root; 
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    sol.flatten(root);
    // Function to print the flattened tree
    function<void(TreeNode*)> printFlattened = [&](TreeNode* node) {
        while (node) {
            cout << node->val << " ";
            node = node->right;
        }
    };
    printFlattened(root);
    return 0;
}