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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> ans; 
        int maxwidth = INT_MIN;
        queue<pair<TreeNode*, long long>> q; 
        q.push({root, 0}); 
        while(!q.empty()){
            int size = q.size();  
            int start = q.front().second; 
            int end = q.back().second; 
            maxwidth = max(maxwidth, end-start+1);
            for(int i = 0; i<size; i++){
                auto [node, idx] = q.front(); 
                q.pop();
                idx -= start;  // Normalise before entering before it can grow exponentially too... 
                if(node->left) q.push({node->left, 2*idx}); 
                if(node->right) q.push({node->right, 2*idx+1}); 
            }
        }
        return maxwidth; 
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    
    Solution sol;
    cout << sol.widthOfBinaryTree(root) << endl; // Output: 4
    return 0;
}