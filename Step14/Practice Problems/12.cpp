#include<bits/stdc++.h>
using namespace std;
// define tree node structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* prev = NULL; 
    TreeNode* first = NULL; 
    TreeNode* second = NULL;
    void inorder(TreeNode* root){
        if(root == NULL) return; 
        inorder(root->left);
        if(prev && prev->val >root->val){
            if(first == NULL){
                first = prev; 
                second = root;
            }
            else second = root;
        }
        prev = root;  
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);     
    }
};
int main() {
    /*
            1
           / \
          3   4
           \
            2
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution sol;
    sol.recoverTree(root);

    // Inorder traversal to verify the tree is corrected
    cout << "Inorder traversal of the corrected BST: ";
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr != NULL || !st.empty()) {
        while(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}