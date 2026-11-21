#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};
class Solution {
public:
    vector<int> getPreorder(TreeNode* root){
        vector<int> preorder; 
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right != NULL && prev->right != cur){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder; 
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    vector<int> preorder = sol.getPreorder(root);
    for(int val : preorder){
        cout << val << " ";
    }
    return 0;
}