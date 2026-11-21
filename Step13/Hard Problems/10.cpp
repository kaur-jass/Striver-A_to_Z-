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
    TreeNode* build(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap){
        if(postStart > postEnd || inStart > inEnd) return NULL; 
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val]; 
        int numsLeft = inRoot - inStart; 
        root->left = build(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot - 1, inMap);
        root->right = build(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, inMap);
        return root; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap; 
        for(int i = 0; i<inorder.size(); i++){
            inMap[inorder[i]] = i; 
        }
        TreeNode* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap); 
        return root; 
    }
};

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);
    // Function to print the tree (Inorder Traversal)
    function<void(TreeNode*)> printInorder = [&](TreeNode* node) {
        if (node == NULL) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    };
    printInorder(root);
    return 0;
}