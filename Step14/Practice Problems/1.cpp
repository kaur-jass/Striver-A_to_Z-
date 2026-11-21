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
    int ceilNode(TreeNode* root, int key) {
        int ceil = -1; // Initialize ceil to -1 (indicating no ceil found)
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->val == key) {
                return current->val; // Exact match found, return it as the ceil
            } else if (current->val < key) {
                current = current->right; // Move right to find larger values
            } else {
                ceil = current->val; // Update ceil to the current node's value
                current = current->left; // Move left to find a closer value
            }
        }

        return ceil; // Return the smallest value greater than or equal to key
    }
};
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    int key = 5;
    int ceilValue = sol.ceilNode(root, key);
    
    if (ceilValue != -1) {
        cout << "Ceil of " << key << " in the BST is: " << ceilValue << endl;
    } else {
        cout << "No ceil found for " << key << " in the BST." << endl;
    }

    return 0;
}