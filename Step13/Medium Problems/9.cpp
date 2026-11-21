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
    void topView(TreeNode* root){
        map<int, int> topView;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, col] = q.front();
            q.pop();
            // If this vertical position is being visited for the first time, store it
            if(topView.find(col) == topView.end()){
                topView[col] = node->val;
            }
            if(node->left){
                q.push({node->left, col - 1});
            }
            if(node->right){
                q.push({node->right, col + 1});
            }
        }
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
    sol.topView(root);
    
    return 0;
}
