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
        TreeNode* curr = root;
        stack<TreeNode*> st;
        vector<int> postorder;
        while(curr != nullptr || !st.empty()){
            if(curr != nullptr){
                st.push(curr); 
                curr = curr->left;
            }
            else{
                TreeNode* temp = st.top()->right; 
                if(temp == nullptr){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                    while(!st.empty() && st.top()->right == temp){
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->data);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }  
        return postorder;
    }
};
int main(){
    // 6, 5, 4, 3, 2, 8,10, 9, 7, 1
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(8);
    root->right->left->right = new TreeNode(9);
    root->right->right->right = new TreeNode(10);
    
    Solution sol; 
    vector<int> ans = sol.postorder(root);
    cout<<"Postorder: ";
    for(int x : ans) cout<<x<<" ";
    return 0;
}