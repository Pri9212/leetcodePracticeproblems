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
    TreeNode* invertTree(TreeNode* root) {
      if(root==NULL) return NULL;

     TreeNode* leftsub= invertTree(root->left);
     TreeNode* rightsub=invertTree(root->right);
     root->right=leftsub;
     root->left=rightsub;
     return root;
    
    }
};