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
    int height(TreeNode* root){
        if(root==NULL)
        return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        int ans=max(lh,rh)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
       if(root==NULL)
       return true;
       int lh=height(root->left) ;
       int rh=height(root->right);
       
      bool leftn= isBalanced(root->left);
      bool rightn=isBalanced(root->right);
    if(abs(lh-rh)<=1&&leftn&&rightn) return true;
      return false;
    }
};