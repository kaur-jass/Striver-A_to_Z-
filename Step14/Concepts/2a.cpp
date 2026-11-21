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
TreeNode* searchBST(TreeNode* root, int val) {
    while(root != NULL){
        if(root->val == val) return root;
        else if(root->val > val) root = root->left;
        else root = root->right;
    }
    return NULL;
}
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;
    TreeNode* result = searchBST(root, val);
    if (result) {
        cout << "Node with value " << val << " found in the BST." << endl;
    } else {
        cout << "Node with value " << val << " not found in the BST." << endl;
    }
    return 0;
}