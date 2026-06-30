class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int n=s.size();
      unordered_map<char ,int> mp; 
      int i=0;
      int j=0;
     while(j < n){
    mp[s[j]]++;

    while(mp['a'] && mp['b'] && mp['c']){
        count += (n-j);
        mp[s[i]]--;
        i++;
    }

    j++;
}
      
        
      return count;
    }
};