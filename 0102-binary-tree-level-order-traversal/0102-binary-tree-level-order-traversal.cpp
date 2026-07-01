
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==NULL) return ans;
     queue<TreeNode*>q;
    

     q.push(root) ;
     while(!q.empty())  {
        int width=q.size();
        vector<int>ansone(width);
       
       for(int i=0;i<width;i++){
        TreeNode* temp=q.front();q.pop();
        ansone[i]=temp->val;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        
       }
       ans.push_back(ansone);
       

     }
     return ans;
    }
};