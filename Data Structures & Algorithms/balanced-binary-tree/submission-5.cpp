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
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }

        return height(root)!=-1;
        

        
    }

    int height(TreeNode* node){
        if(!node)return 0;

        int right_height = height(node->right);
        int left_height = height(node->left);

        int difference = abs(right_height-left_height);

        if(difference>1 || right_height == -1 || left_height == -1)return -1;

        return 1+max(right_height,left_height);

    }

};
