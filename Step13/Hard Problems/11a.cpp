#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
    void preorder(TreeNode* root, string &s){
        if(root == NULL){
            s += "#,";
            return; 
        }
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = ""; 
        preorder(root, s); 
        return s; 
    }
    TreeNode* build(vector<string> &tokens, int &i){
        if(tokens[i] == "#"){
            i++; 
            return NULL; 
        }
        TreeNode* root = new TreeNode(stoi(tokens[i])); 
        i++; 

        root->left = build(tokens, i); 
        root->right = build(tokens, i); 

        return root; 
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        vector<string> tokens; 
        stringstream ss(data);
        string token;

        while(getline(ss, token, ',')){
            tokens.push_back(token); 
        }
        
        int i = 0; 
        return build(tokens, i); 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserializedRoot = codec.deserialize(serialized);
    // Function to print the deserialized tree (Inorder Traversal)
    function<void(TreeNode*)> printInorder = [&](TreeNode* node) {
        if (node == NULL) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    };
    cout << "Deserialized Tree (Inorder): ";
    printInorder(deserializedRoot);
    cout << endl;

    return 0;
}