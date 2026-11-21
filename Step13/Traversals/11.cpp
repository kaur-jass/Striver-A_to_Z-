#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    vector<int> postorder(TreeNode* root){
        if(root == nullptr) return {};
        stack<TreeNode*> st1, st2;
        vector<int> postorder;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* Node = st1.top();
            st1.pop();
            st2.push(Node);
            if(Node->left) st1.push(Node->left);
            if(Node->right) st1.push(Node->right);
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->data);
            st2.pop();
        }
        return postorder;   
    }
}; 
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    Solution sol; 
    vector<int> ans = sol.postorder(root);
    cout<<"Postorder: ";
    for(int x : ans) cout<<x<<" ";
    return 0;
}
