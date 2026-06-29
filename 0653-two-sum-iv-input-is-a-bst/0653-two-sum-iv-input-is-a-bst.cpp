
class Solution {
public:
void storeinorder(TreeNode* root,vector<int>&inorder){
    if(root==NULL) return;
    storeinorder(root->left,inorder);
    inorder.push_back(root->val);
    storeinorder(root->right,inorder);
}
    bool findTarget(TreeNode* root, int k) {
      vector<int>inorder;
      storeinorder(root,inorder);
      int i=0;
      int j=inorder.size()-1;
      while(i<j){
        int sum=inorder[i]+inorder[j];
        if(sum==k) return true;
        else if(sum>k){
            j--;
        }
        else i++;
        
      }
     return false;
    }
};