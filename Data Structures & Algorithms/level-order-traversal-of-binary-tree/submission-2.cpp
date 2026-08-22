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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root) return {};

        queue<TreeNode*> q;

        q.push(root);

        vector<vector<int>> res;

        while(!q.empty()){

            queue<TreeNode*> temp;
            vector<int> v;
            while(!q.empty()){
                TreeNode* node = q.front();
                v.push_back(node->val);
                if(node->left){
                    temp.push(node->left);
                }
                if(node->right){
                    temp.push(node->right);
                }
                q.pop();
                
            }
            res.push_back(v);

            while(!temp.empty()){
                q.push(temp.front());
                temp.pop();
            }

           
        }

        return res;

        
    }
};
