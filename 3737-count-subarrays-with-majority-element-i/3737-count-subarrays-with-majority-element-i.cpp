class Solution {
public:
    
    int countMajoritySubarrays(vector<int>& nums, int target) {
    int anscount=0;
    
     for(int i=0;i<nums.size();i++) {
        
        int c=0;
        for(int j=i;j<nums.size();j++){
            int len=j-i+1;
            if(nums[j]==target) c++;
            if(2*c>len){
                anscount++;
            }
        } 
               
        }
      return anscount; 
    }
};