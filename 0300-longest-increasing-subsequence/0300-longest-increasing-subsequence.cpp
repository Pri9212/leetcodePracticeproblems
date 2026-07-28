class Solution {
public:
    int solveusingrec(vector<int>& nums,int curr,int prev,vector<vector<int>>&dp){
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        if(curr>=nums.size()) return 0;
        int includeans=0;
        if(prev==-1||(nums[curr]>nums[prev])){
            includeans=1+solveusingrec(nums,curr+1,curr,dp);
        }
        int excludeans=0+solveusingrec(nums,curr+1,prev,dp);

        int finalans=max(includeans,excludeans);
        dp[curr][prev+1]=finalans;
        return finalans;
    }
   

    int lengthOfLIS(vector<int>& nums) {
      int prev=-1;
      int curr=0;
      
      int n=nums.size();
      vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       //create ,initialize,send ,receive dp array
       int ans=solveusingrec(nums,curr,prev,dp) ; 
      return ans;
    }
};