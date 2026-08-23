class Solution {
public:
    int solveusingtab(string s1,string s2){
        int n1=s1.length();
        int n2=s2.length();
  vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for(int i=n1-1;i>=0;i--){
    for(int j=n2-1;j>=0;j--){
   int ans=0;
    if(s1[i]==s2[j]){
        dp[i][j]= 1+dp[i+1][j+1];
    }
    else{
        dp[i][j]= max(dp[i][j+1],dp[i+1][j]);
    }
    }
    }
    
    return dp[0][0];
    
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
    return solveusingtab(text1,text2);
    }
};