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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        TreeNode* cur = root;

        while(true) {
            if(cur->val <= val) {
                if(cur->right != NULL) 
                    cur = cur->right;
                else {
                    cur->right = new TreeNode(val);
                    break;
                }
            } 
            else {
                if(cur->left != NULL) 
                    cur = cur->left;
                else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};
int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int val = 5;
    TreeNode* modifiedRoot = sol.insertIntoBST(root, val);
    
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