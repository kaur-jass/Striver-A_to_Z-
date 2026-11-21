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
    vector<int> bottomView(TreeNode* root) {
        map<int, int> bottomView;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, col] = q.front(); 
            q.pop();
            // Update the bottom view for this vertical position
            bottomView[col] = node->val; // always overwrite to get the bottommost node
            if(node->left) q.push({node->left, col - 1});
            if(node->right) q.push({node->right, col + 1});
        }
        vector<int> result;
        for(auto& [col, val] : bottomView){
            result.push_back(val);
        }
        return result;
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
    vector<int> result = sol.bottomView(root);
    
    cout << "Bottom View of the Binary Tree:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
