class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      queue<int>arr;
      //arr.push_back(num[0]);
      int ans=0;
      for(int i:nums){
        mp[i]++;
        arr.push(i);
        while(mp[i]>k){
        int x=arr.front();
                
        arr.pop();
         mp[x]--;
            }
        
       int n=arr.size();
    ans=max(ans,n);
      }
      return ans;  
    }
};