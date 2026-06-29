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
    int maxval(TreeNode* root){
        TreeNode* temp=root;
        if(temp==NULL) return 0;
        while(temp->right){
            temp=temp->right;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL) return root;
    if(root->val==key){
     if(root->left==NULL&&root->right==NULL){
        //delete root;
        return NULL;
     }
     else if(root->left==NULL&&root->right!=NULL){
       //delete root;
        return root->right;
     }
     else if(root->left!=NULL&& root->right==NULL){
        
        return root->left;
     }
     else{
        int predec=maxval(root->left);
        root->val=predec;
        root->left=deleteNode(root->left,predec);
        return root;

     }
    }
    else if(root->val>key){
      root->left=deleteNode(root->left,key);
    }
    else{
    root->right=deleteNode(root->right,key);
    }

    return root;
    }
};