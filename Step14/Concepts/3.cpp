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
TreeNode* findMin(TreeNode* root) {
    if(root == NULL) return NULL;

    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}
TreeNode* findMax(TreeNode* root) {
    if(root == NULL) return NULL;

    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* minNode = findMin(root);
    if (minNode) {
        cout << "Minimum value in the BST: " << minNode->val << endl;
    } else {
        cout << "The BST is empty." << endl;
    }

    TreeNode* maxNode = findMax(root);
    if (maxNode) {
        cout << "Maximum value in the BST: " << maxNode->val << endl;
    } else {
        cout << "The BST is empty." << endl;
    }
    
    return 0;
}