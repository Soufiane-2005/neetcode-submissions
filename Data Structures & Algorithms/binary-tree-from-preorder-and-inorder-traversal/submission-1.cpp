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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> pos;

        for(int i = 0 ; i<inorder.size(); i++){
            pos[inorder[i]]=i;
        }

        return buildTree(preorder,0,preorder.size()-1, inorder, 0 , inorder.size()-1, pos);
        
    }


    TreeNode* buildTree(vector<int>& preorder ,int leftPre,int rightPre, vector<int>& inorder,int leftIn,int rightIn, unordered_map<int,int>& pos){
        if(leftPre>rightPre || leftIn>rightIn){
            return nullptr;
        }

        //first element of preorder is the root: 
        int rootValue = preorder[leftPre];

        TreeNode* root = new TreeNode(rootValue);

        //find root in order: 

        int rootIndex = pos[rootValue];

        //Number of nodes in left subtree: 

        int leftSize = rootIndex - leftIn;

        //build the left subtree: 

        root->left = buildTree(
            preorder,

            leftPre + 1,
            leftPre + leftSize,

            inorder,

            leftIn,
            rootIndex-1,

            pos 
        );

        //build the right subtree:

        root->right = buildTree(
            preorder,

            leftPre + leftSize +1,
            rightPre,

            inorder,

            rootIndex + 1,
            rightIn,

            pos
        );

        // return the root: 

        return root;


    }
};
