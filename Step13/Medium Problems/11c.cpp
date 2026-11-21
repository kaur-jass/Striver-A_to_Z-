#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void preorder(TreeNode* root, vector<int> &ans, int level){
        if(root == NULL) return; 
        if(level == ans.size()) ans.push_back(root->val); 
        preorder(root->left, ans, level+1); 
        preorder(root->right, ans, level+1); 
    }
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans; 
        if(root == NULL) return ans;
        preorder(root, ans, 0);
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    Solution sol;
    vector<int> result = sol.leftSideView(root);
    
    cout << "Left Side View of the Binary Tree:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}