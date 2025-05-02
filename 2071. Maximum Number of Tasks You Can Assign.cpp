// Problem: 2071. Maximum Number of Tasks You Can Assign
// Difficulty: Hard
// Topics: Array, Binary Search, Sorting, Heap (Priority Queue)
// Link: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/
// Approach:
//   - Sort both tasks and workers.
//   - Use binary search to find the maximum number of assignable tasks.
//   - For each candidate number x, use a deque to simulate assigning the x easiest tasks
//     to the x strongest available workers, optionally using pills to boost weaker workers.
// Time Complexity: O(n log n + m log m + log(min(n, m)) * min(n, m))
// Space Complexity: O(n)

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size(), m = workers.size();
        int left = 0, right = min(m, n);
        auto check = [&](int x) {
            int p = pills;
            deque<int> q;
            int i = 0;
            for (int j = m - x; j < m; ++j) {
                while (i < x && tasks[i] <= workers[j] + strength) {
                    q.push_back(tasks[i++]);
                }
                if (q.empty()) {
                    return false;
                }
                if (q.front() <= workers[j]) {
                    q.pop_front();
                } else if (p == 0) {
                    return false;
                } else {
                    --p;
                    q.pop_back();
                }
            }
            return true;
        };
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
