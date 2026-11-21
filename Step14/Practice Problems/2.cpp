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
    int floorNode(TreeNode* root, int key) {
        int floor = -1; // Initialize floor to -1 (indicating no floor found)
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->val == key) {
                return current->val; // Exact match found, return it as the floor
            } else if (current->val > key) {
                current = current->left; // Move left to find smaller values
            } else {
                floor = current->val; // Update floor to the current node's value
                current = current->right; // Move right to find a closer value
            }
        }

        return floor; // Return the largest value less than or equal to key
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
    int floorValue = sol.floorNode(root, key);
    
    if (floorValue != -1) {
        cout << "Floor of " << key << " in the BST is: " << floorValue << endl;
    } else {
        cout << "No floor found for " << key << " in the BST." << endl;
    }

    return 0;
}