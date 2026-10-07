class Solution {
public:
    void rotate(vector<int>& nums, int k) {
     vector<int>arr ;
     
     int n= nums.size();
     if(n<=k) k=k%n;
     for(int i=n-k;i<n;i++){
        arr.push_back(nums[i]);
     }
     for (int i=n-k-1;i>=0;i--){
        nums[i+k]=nums[i];
     }
     for(int i=0;i<k;i++){
        nums[i]=arr[i];
     }
    }
};