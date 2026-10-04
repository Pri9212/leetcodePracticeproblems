class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
      
        // dp[i][j] represents whether substring s[i...j] can form a valid parentheses string
        // where '*' can be treated as '(', ')' or empty string
        vector<vector<bool>> dp(n, vector<bool>(n, false));
      
        // Base case: single character can only be valid if it's '*' (treated as empty)
        for (int i = 0; i < n; ++i) {
            dp[i][i] = (s[i] == '*');
        }
      
        // Fill the dp table for substrings of increasing length
        // Process from bottom to top, left to right in the dp table
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                char leftChar = s[i];
                char rightChar = s[j];
              
                // Case 1: Check if s[i] and s[j] can form a matching pair "()"
                // s[i] can be '(' if it's '(' or '*'
                // s[j] can be ')' if it's ')' or '*'
                // The middle part (if exists) must also be valid
                bool canFormPair = (leftChar == '(' || leftChar == '*') && 
                                   (rightChar == ')' || rightChar == '*') &&
                                   (i + 1 == j || dp[i + 1][j - 1]);
              
                dp[i][j] = canFormPair;
              
                // Case 2: Try to split the substring at different positions
                // If we can find a split point k where both parts are valid,
                // then the whole substring is valid
                for (int k = i; k < j && !dp[i][j]; ++k) {
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }
            }
        }
      
        // Return whether the entire string can form valid parentheses
        return dp[0][n - 1];
    }
};
