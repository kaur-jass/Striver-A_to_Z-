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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root == NULL) return ans; 
        queue<TreeNode*> q; 
        q.push(root); 
        int j = 0; 
        while(!q.empty()){
            int size = q.size(); 
            vector<int> Level; 
            for(int i = 0; i<size; i++){
                TreeNode *Node = q.front(); 
                q.pop(); 
                if(Node->left != NULL) q.push(Node->left); 
                if(Node->right != NULL) q.push(Node->right);
                Level.push_back(Node->val); 
            }
            if(j%2) reverse(Level.begin(), Level.end());
            ans.push_back(Level);    
            j++;  
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
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    
    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}