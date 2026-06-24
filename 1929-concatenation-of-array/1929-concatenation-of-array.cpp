class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
      int n=nums.size(); 
     vector<int> ans;
     int i=0;
    for(int x:nums){
       ans.push_back(x); 
    }
     for(int x:nums){
        ans.push_back(x);
    }
     return ans; 

    }
};