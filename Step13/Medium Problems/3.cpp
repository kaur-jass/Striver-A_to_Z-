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
    int maxDepth(int &diameter, TreeNode* root) {
        if(root == NULL) return 0; 
        int leftDepth =  maxDepth(diameter, root->left); 
        int rightDepth =  maxDepth(diameter, root->right);
        diameter = max(leftDepth + rightDepth, diameter);
        return (1 + max(leftDepth, rightDepth)); 
    }
    int diameterOfBinaryTree(TreeNode* root) { 
        int diameter = 0; 
        maxDepth(diameter, root); 
        return diameter;   
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution sol;
    cout << sol.diameterOfBinaryTree(root) << endl; // Output: 3
    return 0;
}