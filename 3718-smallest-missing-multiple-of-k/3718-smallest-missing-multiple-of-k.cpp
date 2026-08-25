class Solution {
public:
    
    int missingMultiple(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int target=k;
    
    for(int i=0;i<nums.size();i++) {
        if(i==nums.size()&& nums[i]<target){
           return target;  
        }
       if(nums[i]==target){
        target+=k;
       }
       else if(nums[i]>target){
        return target;
       }
    } 
    return target;  
    }
};