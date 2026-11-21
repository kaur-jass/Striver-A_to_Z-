#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data; 
    Node* left; 
    Node* right; 
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    vector<int> preorder(Node* root){
         vector<int> preorder; 
        if(root == nullptr) return preorder;
        stack<Node*> st; 
        st.push(root);
        while(!st.empty()){
            Node* Node = st.top(); 
            st.pop();
            preorder.push_back(Node->data);
            if(Node->right) st.push(Node->right);
            if(Node->left) st.push(Node->left);
        }
        return preorder;
    }
}; 
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    
    Solution sol; 
    vector<int> ans = sol.preorder(root);
    cout<<"Preorder: ";
    for(int x : ans) cout<<x<<" ";
    return 0;
}