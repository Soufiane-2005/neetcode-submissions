/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null";

        string left_side = serialize(root->left);
        string right_side = serialize(root->right);

        return to_string(root->val) + ","+left_side+","+right_side;
    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
        
    }

    TreeNode* build(stringstream& ss){
        string node;

        getline(ss, node, ',');

        if(node=="null") return nullptr;

        TreeNode* root = new TreeNode(stoi(node));

        root->left = build(ss);
        root->right = build(ss);

        return root;



    }
};
