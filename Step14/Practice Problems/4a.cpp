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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL; 
        if(root->val > key) root->left = deleteNode(root->left, key); 
        else if(root->val < key) root->right = deleteNode(root->right, key); 
        else{ // Node found
            // Case 1 : No Left
            if(!root->left) return root->right; 
            // Case 2 : No Right
            if(!root->right) return root->left; 
            // Case 3 : Two Children 
            // Inorder Successor 
            TreeNode* temp = root->right; 
            while(temp->left) temp = temp->left;
            root->val = temp->val; 
            root->right = deleteNode(root->right, temp->val); 
        }
        return root; 
    }
};
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;
    int key = 3;
    TreeNode* modifiedRoot = sol.deleteNode(root, key);
    
    // Function to print the modified tree (Inorder Traversal)
    function<void(TreeNode*)> printInorder = [&](TreeNode* node) {
        if (node == NULL) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    };
    
    cout << "Inorder traversal of the modified BST: ";
    printInorder(modifiedRoot);
    cout << endl;

    return 0;
}