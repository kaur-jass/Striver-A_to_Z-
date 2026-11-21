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
    void traverse(TreeNode* root,vector<tuple<int, int, int>> &c_v, int rows, int cols){
        if(root == NULL) return;
        c_v.push_back({cols, rows, root->val}); 
        traverse(root->left, c_v, rows+1, cols-1); 
        traverse(root->right, c_v, rows+1, cols+1); 
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> column_val;
        traverse(root, column_val, 0, 0); 
        sort(column_val.begin(), column_val.end()); 
        vector<vector<int>> ans;
        int i = 0;
        int n = column_val.size();
        while(i < n) {
            int col = get<0>(column_val[i]);
            vector<int> cols;
            while(i < n && get<0>(column_val[i]) == col) {
                cols.push_back(get<2>(column_val[i]));
                i++;
            }
            ans.push_back(cols);
        }
        return ans;
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
    vector<vector<int>> result = sol.verticalTraversal(root);
    
    cout << "Vertical Order Traversal:" << endl;
    for (const auto& column : result) {
        for (int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}