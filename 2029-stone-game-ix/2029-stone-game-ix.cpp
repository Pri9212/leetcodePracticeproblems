class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // Number of stones divisible by 3
        if (cnt[0] % 2 == 0) {
            // Alice can win if both types 1 and 2 exist
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // cnt[0] is odd
        return abs(cnt[1] - cnt[2]) > 2;
    }
};