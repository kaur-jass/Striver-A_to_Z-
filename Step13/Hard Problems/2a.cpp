#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode* left, TreeNode* right) : data(data), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root) return root; 
        TreeNode * left = lowestCommonAncestor(root->left, p, q); 
        TreeNode * right = lowestCommonAncestor(root->right, p, q); 
        if(left && right) return root; 
        return left ? left : right; 
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    
    Solution sol;
    TreeNode* p = root->left; // Node 2
    TreeNode* q = root->right; // Node 3
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    
    if (lca) {
        cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor does not exist." << endl;
    }
    
    return 0;
}