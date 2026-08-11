class Solution {
public:
    int binarysearch(vector<int>& nums,int target){
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid] == target){
                return 1;
            }
            else if(nums[mid]>target){
              e=mid-1; 
            }
            else{
               s=mid+1;
            }
        
        }
        return 0;

    }
    int missingInteger(vector<int>& nums) {
        int i=1;
        int sum=nums[0];
    while(i<nums.size() && nums[i]== nums[i-1]+1){
    sum+=nums[i];
    i++;
    }
    sort(nums.begin(),nums.end());
    while(binarysearch(nums,sum)){
        sum++;
    }
    return sum;
       
    }
};