class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);

        // Coordinate compression
        vector<int> sortedPrefix = prefix;
        sort(sortedPrefix.begin(), sortedPrefix.end());
        sortedPrefix.erase(unique(sortedPrefix.begin(), sortedPrefix.end()), sortedPrefix.end());

        // Fenwick Tree
        vector<int> bit(sortedPrefix.size() + 1, 0);
        auto update = [&](int idx, int val) {
            for (++idx; idx < (int)bit.size(); idx += idx & -idx)
                bit[idx] += val;
        };
        auto query = [&](int idx) {
            int sum = 0;
            for (++idx; idx > 0; idx -= idx & -idx)
                sum += bit[idx];
            return sum;
        };

        long long ans = 0;
        for (int i = 0; i <= n; ++i) {
            int idx = lower_bound(sortedPrefix.begin(), sortedPrefix.end(), prefix[i]) - sortedPrefix.begin();
            ans += query(idx - 1); // count of prefix sums smaller than current
            update(idx, 1);
        }
        return ans;
    }
};
