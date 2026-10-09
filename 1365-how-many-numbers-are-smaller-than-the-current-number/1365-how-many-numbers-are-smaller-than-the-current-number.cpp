class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans(nums.size());
        for(int i:nums){
        mp[i]++;
        }
    for(int i=0;i<nums.size();i++){
    for(auto j:mp){
        if(nums[i]>j.first){
         ans[i]+=j.second;
        }
    }
    }
    return ans;
    }
};