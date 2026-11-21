#include <bits/stdc++.h>
using namespace std;

// define tree node structure
struct TreeNode {
    // value of the node
    int val;
    // pointer to the left child
    TreeNode* left;
    // pointer to the right child
    TreeNode* right;
    // constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution class
class Solution {
public:
    // find inorder successor by building inorder list and binary searching
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;
        while (root != nullptr) {
            if (p->val < root->val) {
                successor = root; // potential successor
                root = root->left; // go left to find smaller successor
            } else {
                root = root->right; // go right to find larger values
            }
        }
        return successor; // return the last recorded successor
    }
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode* predecessor = nullptr;
        while (root != nullptr) {
            if (p->val > root->val) {
                predecessor = root; // potential predecessor
                root = root->right; // go right to find larger predecessor
            } else {
                root = root->left; // go left to find smaller values
            }
        }
        return predecessor; // return the last recorded predecessor
    }
};


// program entry
int main() {
    // construct BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // pick node p (value 4)
    TreeNode* p = root->left->right;

    // compute successor
    Solution solution;
    TreeNode* successor = solution.inorderSuccessor(root, p);
    

    // print result
    if (successor != nullptr) {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    } else {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    // compute predecessor
    TreeNode* predecessor = solution.inorderPredecessor(root, p);

    // print result
    if (predecessor != nullptr) {
        cout << "Inorder Predecessor of " << p->val << " is: " << predecessor->val << endl;
    } else {
        cout << "Inorder Predecessor of " << p->val << " does not exist." << endl;
    }
    // done
    return 0;
}
