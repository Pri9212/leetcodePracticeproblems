class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        queue<int> q;

        int ans = 0;

        for (int i : nums) {
            q.push(i);
            mp[i]++;

            // If frequency becomes greater than k,
            // remove elements from the front
            while (mp[i] > k) {
                int x = q.front();
                q.pop();
                mp[x]--;
            }

            ans = max(ans, (int)q.size());
        }

        return ans;
    }
};