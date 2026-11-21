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
    bool findTarget(TreeNode* root, int target, TreeNode* &targetNode){
        // Base Case 
        if(root == NULL) return false; 
        if(root->val == target){
            targetNode = root; 
            return true; 
        }
        // As soon as target is found in left subtree, it won’t search right
        // Saves unnecessary recursion → more efficient
        return findTarget(root->left, target, targetNode) || findTarget(root->right, target, targetNode);
    }
    int minTime(TreeNode* root, int target) {
        // Step 1 : Build a map to store parent so that i can traverse back 
        unordered_map<TreeNode*, TreeNode*> parent;
        Parent(root, parent); 
        unordered_map<TreeNode*, bool> visited; 
        // Step 2 : BFS fro getting levels 
        // target is the value of one of the nodes in the tree.
        // and mark the node visited once u go there so not to come there again 
        queue<TreeNode*> q; 
        TreeNode* targetNode = NULL;
        findTarget(root, target, targetNode);
        if(targetNode == NULL) return 0;
        q.push(targetNode); 
        visited[targetNode] = true; 
        int time = -1; 
        while(!q.empty()){
            int size = q.size(); 
            time++; 
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
                if(parent.count(node) && !visited[parent[node]]){ // returns 1 if node is present in the map and 0
                    // if not and doesnot modify map if root is not present in the map by adding NULL value for root in the map
                    q.push(parent[node]); 
                    visited[parent[node]] = true;
                }
            }    
        }
        return time; 
    }
};

// Driver code
int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    // Create solution object
    Solution sol;

    // Set target node to burn from
    int target = 1;

    // Print the minimum time to burn the tree
    cout << "Minimum time to burn the tree: " << sol.minTime(root, target) << endl;

    return 0;
}
