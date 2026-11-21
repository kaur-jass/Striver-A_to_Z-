#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode* left, TreeNode* right) : data(data), left(left), right(right) {}
};
class Solution {
public:
    bool lcal(TreeNode* root, TreeNode* p,vector<TreeNode*> &ans1 ){
        if(root == NULL) return false; 
        ans1.push_back(root); 
        if(root == p) return true; 
        if(lcar(root->left, p, ans1) || lcar(root->right, p, ans1)) return true; 
        ans1.pop_back();
        return false; 
    }
    bool lcar(TreeNode* root, TreeNode* q,vector<TreeNode*> &ans2){
        if(root == NULL) return false; 
        ans2.push_back(root); 
        if(root == q) return true; 
        if(lcal(root->left, q, ans2) || lcal(root->right, q, ans2)) return true; 
        ans2.pop_back();
        return false; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ans1, ans2; 
        lcal(root, p, ans1); 
        lcar(root, q, ans2); 
        TreeNode* res = NULL; 
        for(int i = 0; i < min(ans1.size(), ans2.size()); i++){
            if(ans1[i] == ans2[i]) res = ans1[i];
            else break; // here break because once paths differ they can never merge again  
        }
        return res;
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
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    
    Solution sol;
    TreeNode* p = root->left; // Node 2
    TreeNode* q = root->right; // Node 3
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    
    if (lca) {
        cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor does not exist." << endl;
    }
    
    return 0;
}