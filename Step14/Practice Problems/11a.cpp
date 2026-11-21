#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BST Iterator
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse; // false = normal inorder, true = reverse inorder

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        // depending on direction
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);

        return node->val;
    }

private:
    void pushAll(TreeNode* node) {
        while(node != NULL) {
            st.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
};

// Solution
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator l(root, false); // next smallest
        BSTIterator r(root, true);  // next largest

        int i = l.next();
        int j = r.next();

        while(i < j) {
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};



// -------- MAIN FUNCTION --------
int main() {
    /*
            5
           / \
          3   6
         / \   \
        2   4   7
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution obj;

    int k = 9;

    if(obj.findTarget(root, k))
        cout << "Pair exists\n";
    else
        cout << "Pair does NOT exist\n";

    return 0;
}