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

class Solution {
    int diameter = 0;
public:
    
    int diameterOfBinaryTree(TreeNode* root) {

        if(!root){
            return 0;
        }

        int height_left = height(root->left);
        int height_right = height(root->right);

        diameter = max(diameter, height_left+height_right);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return diameter;




  
        
        
    }

    int height(TreeNode* node){
        if(!node){
            return 0;
        }
        return 1 + max(height(node->left),height(node->right));
    }

};
