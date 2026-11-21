#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
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
    void Parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        // Base Case 
        if(root == NULL) return; 
        if(root->left) parent[root->left] = root; 
        if(root->right) parent[root->right] = root;
        Parent(root->left, parent); 
        Parent(root->right, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1 : Build a map to store parent so that i can traverse back 
        unordered_map<TreeNode*, TreeNode*> parent;
        Parent(root, parent); 
        unordered_map<TreeNode*, bool> visited; 
        // Step 2 : BFS fro getting levels 
        // target is the value of one of the nodes in the tree.
        // and mark the node visited once u go there so not to come there again 
        queue<TreeNode*> q; 
        q.push(target); 
        visited[target] = true; 
        while(k--){
            int size = q.size(); 
            for(int i = 0;i < size; i++){
                auto node = q.front(); 
                q.pop(); 
                if(node->left && !visited[node->left]){
                    q.push(node->left); 
                    visited[node->left] = true; 
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right); 
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]); 
                    visited[parent[node]] = true;
                }
            }    
        }
        vector<int> ans; 
        while(!q.empty()){
            ans.push_back(q.front()->val); 
            q.pop(); 
        }
        return ans; 
    }
};

// --- Driver Code ---
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

     // Node with value 5
    TreeNode* target = root->left;
    int k = 2;

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}