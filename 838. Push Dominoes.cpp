// Problem: 838. Push Dominoes
// Difficulty: Medium
// Topics: Two Pointers, String, Dynamic Programming, Breadth-First Search
// Link: https://leetcode.com/problems/push-dominoes/
// Approach:
//   - Use BFS to simulate the falling process of dominoes.
//   - Track the earliest time each domino is pushed.
//   - At each step, propagate the force to the next position if possible.
//   - If multiple forces arrive at the same time, they cancel each other.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        queue<int> q;
        vector<int> time(n, -1);
        vector<string> force(n);

        for (int i = 0; i < n; ++i) {
            if (dominoes[i] != '.') {
                q.push(i);
                time[i] = 0;
                force[i].push_back(dominoes[i]);
            }
        }

        string ans(n, '.');
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (force[i].size() == 1) {
                char f = force[i][0];
                ans[i] = f;
                int j = (f == 'L') ? (i - 1) : (i + 1);
                if (j >= 0 && j < n) {
                    int t = time[i];
                    if (time[j] == -1) {
                        q.push(j);
                        time[j] = t + 1;
                        force[j].push_back(f);
                    } else if (time[j] == t + 1) {
                        force[j].push_back(f);
                    }
                }
            }
        }

        return ans;
    }
};
