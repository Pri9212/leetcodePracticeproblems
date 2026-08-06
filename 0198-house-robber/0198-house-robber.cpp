class Solution {
public:
    int solveusingrec(vector<int>& nums,int index,vector<int>&dp){
        //base case
        if(index>=nums.size()) return 0;
       
        if(dp[index]!=-1){
            return dp[index];
        }
       
        int includekaans=nums[index]+solveusingrec(nums,index+2,dp);
        
        
        int excludekaans=solveusingrec(nums,index+1,dp);
         dp[index]=max(includekaans,excludekaans);
        return dp[index];
    }
    int rob(vector<int>& nums) {
      int index=0;
      int n=nums.size();
      vector<int>dp(n+1,-1);
      int ans=solveusingrec(nums,index,dp);
      return ans;  
    }
};