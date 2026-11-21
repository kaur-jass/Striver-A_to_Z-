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
    TreeNode* childrenSum(TreeNode* root){
        if (root == NULL) return NULL;
        // Step 1 - Two case to check the children sum property is violated or not. ( TOP DOWN APPROACH )
        int childSum = 0; 
        if (root->left != NULL) childSum += root->left->val;    
        if (root->right != NULL) childSum += root->right->val;
        if (childSum  >= root->val) {
            root->val = childSum;
        }
        else{
            if (root->left != NULL) root->left->val = root->val;
            else if (root->right != NULL) root->right->val = root->val;
        }

        childrenSum(root->left);
        childrenSum(root->right);

        // Step 2 - Now we will check the children sum property is violated or not. ( BOTTOM UP APPROACH )

        int total = 0; 
        if (root->left != NULL) total += root->left->val;
        if (root->right != NULL) total += root->right->val;
        if (root->left != NULL || root->right != NULL) root->val = total;
        return root;
    }

};


int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* modifiedRoot = sol.childrenSum(root);
    // Function to print the modified tree (Inorder Traversal)
    function<void(TreeNode*)> printInorder = [&](TreeNode* node) {
        if (node == NULL) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    };
    cout << "Modified Tree (Inorder Traversal): ";
    printInorder(modifiedRoot);

    cout << endl;

    return 0;
}
                          