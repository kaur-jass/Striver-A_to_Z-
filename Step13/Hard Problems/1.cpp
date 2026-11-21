#include<bits/stdc++.h>
using namespace std; 

struct TreeNode {
    int data; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode* left, TreeNode* right) : data(data), left(left), right(right) {}
};

class Solution {
public:
    bool helper(TreeNode* root, int node, vector<int> &ans){
        if(root == NULL) return false; 
        ans.push_back(root->data);
        if(root->data == node) return true; 
        bool left = helper(root->left, node, ans); 
        if(left) return true;
        bool right = helper(root->right, node, ans); 
        if(right) return true;
        ans.pop_back();
        return false;
    }
    vector<int> roottoleaf(TreeNode* root, int node) {
        vector<int> ans; 
        if(root == NULL) return ans;
        helper(root, node, ans); 
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    
    Solution sol;
    int targetNode = 8;
    vector<int> result = sol.roottoleaf(root, targetNode);
    
    cout << "Path from root to node " << targetNode << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}