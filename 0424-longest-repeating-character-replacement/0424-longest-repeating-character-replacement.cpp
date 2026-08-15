class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        queue<char> q;

        int maxi = 0;
        int ans = 0;

        for (char ch : s) {
            q.push(ch);
            mp[ch]++;

            maxi = max(maxi, mp[ch]);

            while ((int)q.size() - maxi > k) {
                char x = q.front();
                q.pop();
                mp[x]--;
            }

            ans = max(ans, (int)q.size());
        }

        return ans;
    }
};