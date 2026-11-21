#include<bits/stdc++.h>
using namespace std;

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
    TreeNode* pre(vector<int>& preorder, int& i , int bound){
        int n = preorder.size(); 
        if(i == n || preorder[i] > bound) return NULL; 
        
        TreeNode* root = new TreeNode(preorder[i++]); 
        
        root->left = pre(preorder, i, root->val); 
        root->right = pre(preorder, i, bound); 
        
        return root; 
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return pre(preorder, i, INT_MAX);         
    }
};

// 🔹 Inorder Traversal (should be sorted)
void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 🔹 Preorder Traversal (should match input)
void preorderPrint(TreeNode* root){
    if(!root) return;
    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){
    Solution s; 
    vector<int> preorder = {8,5,1,7,10,12}; 
    
    TreeNode* root = s.bstFromPreorder(preorder); 
    
    cout << "Inorder (sorted BST): ";
    inorder(root);
    
    cout << "\nPreorder (original): ";
    preorderPrint(root);

    return 0; 
}