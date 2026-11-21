#include<bits/stdc++.h>
using namespace std;
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
    int height(TreeNode* root){
        if (root == NULL) return 0;
        int leftHeight = height(root->left);
        if (leftHeight == -1) return -1; // Left subtree is not balanced
        int rightHeight = height(root->right);
        if (rightHeight == -1) return -1; // Right subtree is not balanced
        if (abs(leftHeight - rightHeight) > 1) return -1; // Current node is not balanced
        return 1 + max(leftHeight, rightHeight); // Return height of the current node
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution sol;
    cout << sol.isBalanced(root) << endl; // Output: 1 (true)
    return 0;
}