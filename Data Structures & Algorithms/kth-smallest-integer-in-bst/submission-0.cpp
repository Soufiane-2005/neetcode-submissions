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
    int kth = 1;
public:
    int kthSmallest(TreeNode* root, int k) {

        
        if(!root->left && !root->right){
            if(kth == k){
                return root->val;
            }
            kth++;
            return -1;
        }

        if(root->left){
            int x = kthSmallest(root->left, k);
            if(x!=-1){
                return x;
            }
        }

        if(kth == k){
            return root->val;
        }
        kth++;

        if(root->right){
            int x = kthSmallest(root->right, k);
            if(x!=-1){
                return x;
            }
        }
        return -1;
        











    }
};
