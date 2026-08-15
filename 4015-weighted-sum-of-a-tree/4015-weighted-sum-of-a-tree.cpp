class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<int> depth(n, 0);
        depth[0] = 1;

        int h = 1;

        for (int i = 1; i < n; i++) {
            if (depth[i] != 0)
                continue;

            int cur = i;
            vector<int> path;

            while (depth[cur] == 0) {
                path.push_back(cur);
                cur = parent[cur];
            }

            int d = depth[cur];

            for (int j = path.size() - 1; j >= 0; j--) {
                d++;
                depth[path[j]] = d;
                h = max(h, d);
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (h - depth[i] + 1);
        }

        return ans;
    }
};