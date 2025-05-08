// Problem: 3342. Find Minimum Time to Reach Last Room II
// Difficulty: Hard
// Topics: Graph, Dijkstra, Priority Queue
// Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/
// Approach:
//   - Dijkstra’s algorithm on a grid with additional movement penalty.
//   - Each move adds (i + j) % 2 + 1 to the time along with waiting for moveTime.
//   - Use a priority queue to process the smallest-time node first.
// Time Complexity: O(n * m * log(n * m))
// Space Complexity: O(n * m)

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0});
        int dirs[5] = {-1, 0, 1, 0, -1};

        while (1) {
            auto [d, i, j] = pq.top();
            pq.pop();

            if (i == n - 1 && j == m - 1) {
                return d;
            }
            if (d > dist[i][j]) {
                continue;
            }

            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];

                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int t = max(moveTime[x][y], dist[i][j]) + (i + j) % 2 + 1;
                    if (dist[x][y] > t) {
                        dist[x][y] = t;
                        pq.push({t, x, y});
                    }
                }
            }
        }
    }
};
