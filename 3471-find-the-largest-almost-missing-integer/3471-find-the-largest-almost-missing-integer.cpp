class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
    map<int,int>mp;
    int n= nums.size();
    if(n==k){
        return *max_element(nums.begin(),nums.end());
    }
   
    //if(nums[0]==nums[n-1]) return -1;
    for(int i=0;i<n;i++){
        
           mp[nums[i]]++;
        
    }
    if(k==1){
    sort(nums.begin(),nums.end(),greater<int>());
    for(int i:nums){
        if(mp[i]==1) return i;
    }
    return -1;
    }
    if(mp[nums[0]]==1&&mp[nums[n-1]]==1){
        return max(nums[0],nums[n-1]);
    }
    else if(mp[nums[0]]==1){
        return nums[0];
    }
    else if(mp[nums[n-1]]==1){
        return nums[n-1];
    }
    else{
        return -1;
    }

    }
};