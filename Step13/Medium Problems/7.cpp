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
    bool isleaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL); 
    }
    void addleftBoundary(vector<int> &ans, TreeNode* root){
        TreeNode* curr = root; 
        while(curr){
            if(!isleaf(curr)) ans.push_back(curr->val); 
            if(curr->left) curr = curr->left; 
            else curr = curr->right; 
        }
    }
    void addrightBoundary(vector<int> &ans, TreeNode* root){
        TreeNode* curr = root; 
        vector<int> temp; 
        while(curr){
            if(!isleaf(curr)) temp.push_back(curr->val); 
            if(curr->right) curr = curr->right; 
            else curr = curr->left; 
        }
        reverse(temp.begin(), temp.end()); 
        for(auto i : temp) ans.push_back(i); 
    }

    void addleaf(vector<int> &ans, TreeNode* root){
        if(isleaf(root)){
            ans.push_back(root->val); 
            return; 
        }
        if(root->left) addleaf(ans, root->left); 
        if(root->right) addleaf(ans, root->right); 
    }

    vector<int> printBoundary(TreeNode* root){
        vector<int> ans; 
        if(root == NULL) return ans;
        if(!isleaf(root)) ans.push_back(root->val);
        addleftBoundary(ans, root->left);
        addleaf(ans, root);
        addrightBoundary(ans, root->right);
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
    
    Solution sol;
    vector<int> result = sol.printBoundary(root);
    
    cout << "Boundary Traversal of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}