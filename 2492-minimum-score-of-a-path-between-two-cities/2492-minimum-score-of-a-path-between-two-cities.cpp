// class Solution {
// public:
//     int minScore(int n, vector<vector<int>>& roads) {
        
//     }
// };
// #include <bits/stdc++.h>
//using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        vector<int> visited(n + 1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;

        int minScore = INT_MAX;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            for (auto& [next, dist] : graph[city]) {
                minScore = min(minScore, dist);
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }

        return minScore;
    }
};
