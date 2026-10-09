class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int res=0,a=0;
        sort(nums.begin(),nums.end());
        vector<int>arr;
        for (int i=0;i<nums.size();i++){
            a=a^nums[i];
            res=res^nums[i];
           
            if(a==0) {
            res=res^nums[i];
            arr.push_back(nums[i]);
            }
            a=nums[i];
        }
        for(int i=1;i<=nums.size();i++){
            res=res^i;
        }
        arr.push_back(res);
        return arr;
    }
};