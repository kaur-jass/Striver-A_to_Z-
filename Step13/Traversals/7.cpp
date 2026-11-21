
#include <bits/stdc++.h>
using namespace std;

// TreeNode structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    // Constructor to initialize
    // the TreeNode with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    private:
    // Function to perform inorder traversal
    // of the tree and store values in 'arr'
    void recursivePostorder(TreeNode* root, vector<int> &arr){
        // If the current Tree is NULL
        // (base case for recursion), return
        if(root == nullptr){
            return;
        }
        // Recursively traverse the left subtree
        recursivePostorder(root->left, arr);
        // Recursively traverse the right subtree
        recursivePostorder(root->right, arr);
        // Push the current TreeNode's
        // value into the vector
        arr.push_back(root->data);
    }
    
    public:
    // Function to initiate postorder traversal
    // and return the resulting vector
    vector<int> postorder(TreeNode* root){
        // Create an empty vector to
        // store postorder traversal values
        vector<int> arr;
        // Call the postorder traversal function
        recursivePostorder(root, arr);
        // Return the resulting vector
        // containing postorder traversal values
        return arr;
    }
};

// Main function
int main()
{
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol = Solution();
    // Getting postorder traversal
    vector<int> result = sol.postorder(root);

    // Displaying the postorder traversal result
    cout << "Postorder Traversal: ";
    // Output each value in the
    // postorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
