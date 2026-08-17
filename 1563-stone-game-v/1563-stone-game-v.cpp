class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, stoneValue, prefix, dp);
    }

private:
    int solve(int i, int j,
              vector<int>& a,
              vector<int>& prefix,
              vector<vector<int>>& dp) {

        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        int leftSum = 0;
        int rightSum = prefix[j + 1] - prefix[i];

        for (int k = i; k < j; k++) {

            leftSum += a[k];
            rightSum -= a[k];

            // Alice keeps left part
            if (leftSum < rightSum) {

                // Pruning
                if (ans >= 2 * leftSum)
                    continue;

                ans = max(ans,
                          leftSum + solve(i, k,
                                          a, prefix, dp));
            }

            // Alice keeps right part
            else if (leftSum > rightSum) {

                // Pruning
                if (ans >= 2 * rightSum)
                    break;

                ans = max(ans,
                          rightSum + solve(k + 1, j,
                                           a, prefix, dp));
            }

            // Equal sums: Alice can choose either
            else {

                ans = max(ans,
                          leftSum + solve(i, k,
                                          a, prefix, dp));

                ans = max(ans,
                          rightSum + solve(k + 1, j,
                                           a, prefix, dp));
            }
        }

        return dp[i][j] = ans;
    }
};