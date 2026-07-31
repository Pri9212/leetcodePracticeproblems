class Solution {
public:
    int minimumPushes(string word) {
      unordered_map<char,int>mp;
      int ans=0;
      vector<int>arr;
      for(char ch:word){
        mp[ch]++;
      }
      for(auto m:mp){
        arr.push_back(m.second);
      }
      sort(arr.begin(), arr.end(), greater<int>());
      vector<int>res(arr.size());
      int n=arr.size();
      partial_sum(arr.begin(), arr.end(), res.begin());
      if(n<=8){
       ans= res[n-1]*1; 
      }
      else if(n>8&&n<=16){
        ans=res[7]*1+(res[n-1]-res[7])*2;
      }
      else if(n>16&&n<=24){
       ans=res[7]*1+(res[15]-res[7])*2+(res[n-1]-res[15])*3;   
      }
      else{
        ans=res[7]*1+(res[15]-res[7])*2+(res[23]-res[15])*3+(res[n-1]-res[23])*4; 
      }
      return ans;
    }
};