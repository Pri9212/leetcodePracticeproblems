class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    vector<int>ans;
    
    int i=0;
    int j=n; 
    while(i<n&&j<nums.size()){
        ans.push_back(nums[i]);
        i++;
        ans.push_back(nums[j]);
         j++;

    } 
    while(j<nums.size()) {
        ans.push_back(nums[j]);
        j++;
    }
    while(i<n){
        ans.push_back(nums[i]);
        i++;
    }
    return ans; 
    }
};