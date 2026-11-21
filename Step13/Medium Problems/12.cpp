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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true; 
        if(p == NULL || q == NULL) return false; 
        if(p->val != q->val) return false; 
        return isSameTree(p->left,q->right) && isSameTree(p->right,q->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return false; 
        return isSameTree(root->left, root->right); 
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    Solution sol;
    cout << sol.isSymmetric(root) << endl; // Output: 1 (true)
    
    return 0;
}