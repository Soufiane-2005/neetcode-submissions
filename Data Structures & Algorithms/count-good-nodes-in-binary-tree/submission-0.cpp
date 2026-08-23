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
    int res = 1;
public:
    int goodNodes(TreeNode* root) {

        if(root->right){
            if(root->val <= root->right->val){
                res+=1;
            }
            root->right->val = max(root->right->val, root->val);
            int x = goodNodes(root->right);
        }

        if(root->left){
            if(root->val <= root->left->val){
                res+=1;
            }
            root->left->val = max(root->left->val, root->val);
            int x = goodNodes(root->left);
        }

        return res;

        
        
    }
};
