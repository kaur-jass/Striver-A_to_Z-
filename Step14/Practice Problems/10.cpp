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

class BSTIterator {
public:
    stack<TreeNode*> st;  
    void pushLeft(TreeNode* root){
        while(root  != NULL){
            st.push(root); 
            root = root->left; 
        }
    }
    BSTIterator(TreeNode* root) {
        pushLeft(root); 
    }
    
    int next() {
        TreeNode* Node = st.top(); 
        st.pop(); 
        if(Node->right != NULL){
            pushLeft(Node->right); 
        }
        return Node->val; 
    }
    
    bool hasNext() {
        return !st.empty(); 
    }
};

int main() {
    /*
            7
           / \
          3   15
             /  \
            9   20
    */

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);

    cout << "BST in sorted order: ";

    while(it.hasNext()) {
        cout << it.next() << " ";
    }

    return 0;
}