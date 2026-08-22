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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root)return false;

        if(isSameTree(root,subRoot)) return true;

        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }


    bool isSameTree(TreeNode* tree1, TreeNode* tree2){

        if(!tree1 && !tree2) return true;
        if(!tree1 && tree2 || tree1 && !tree2 || tree1->val != tree2->val)return false;

        
        if(!tree1->right && !tree2->right && !tree1->left && !tree2->left){
            return true;
        }else{
            return isSameTree(tree1->right, tree2->right) && isSameTree(tree1->left, tree2->left);
        }
        

        
    }
};
