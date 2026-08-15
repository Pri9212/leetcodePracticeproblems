class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
        ans=ans^nums[i];
        }
        if(ans!=0){
            return nums.size();
        }
        else{
            for(int num:nums){
                if (num!=0)
                return nums.size()-1;
            }

        }
        return 0;
    }
};