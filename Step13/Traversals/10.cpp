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
    vector<int> inorder(TreeNode* root){
        stack<TreeNode*> st; 
        TreeNode* Node = root;
        vector<int> inorder;         
        while(!st.empty() || Node != NULL){
            if(Node != NULL){
                st.push(Node);
                Node = Node->left;
            }
            else{
                Node = st.top();
                st.pop();
                inorder.push_back(Node->data);
                Node = Node->right;
            }
        }
        return inorder;
    }
}; 
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    Solution sol; 
    vector<int> ans = sol.inorder(root);
    cout<<"Inorder: ";
    for(int x : ans) cout<<x<<" ";
    return 0;
}
