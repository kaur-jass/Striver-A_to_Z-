#include<bits/stdc++.h>
using namespace std; 

struct TreeNode {
    int data; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root == NULL) return ans; 
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()){
            int size = q.size(); 
            vector<int> Level; 
            for(int i = 0; i<size; i++){
                TreeNode *Node = q.front(); 
                q.pop(); 
                if(Node->left != NULL) q.push(Node->left); 
                if(Node->right != NULL) q.push(Node->right);
                Level.push_back(Node->data); 
            }
            ans.push_back(Level); 
        }
        return ans; 
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);
    
    cout << "Level Order Traversal: " << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}