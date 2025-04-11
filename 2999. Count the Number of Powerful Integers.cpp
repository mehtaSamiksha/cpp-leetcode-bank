// Problem: 2999. Count the Number of Powerful Integers
// Difficulty: Medium
// Topic: Digit DP, Recursion, String
// Link: https://leetcode.com/problems/count-the-number-of-powerful-integers
// Approach: Use digit DP with memoization. Count how many numbers between [start, finish]
//           have all digits ≤ limit and end with string s. Count separately for finish and start - 1.
// Time Complexity: O(digits * 10) where digits = number of digits in the input numbers
// Space Complexity: O(digits) recursion depth + O(digits) memo array

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string t = to_string(start - 1);
        long long f[20];
        memset(f, -1, sizeof(f));

        auto dfs = [&](this auto&& dfs, int pos, int lim) -> long long {
            if (t.size() < s.size()) return 0;
            if (!lim && f[pos] != -1) return f[pos];
            if (t.size() - pos == s.size()) return lim ? s <= t.substr(pos) : 1;

            long long ans = 0;
            int up = min(lim ? t[pos] - '0' : 9, limit);
            for (int i = 0; i <= up; ++i) {
                ans += dfs(dfs, pos + 1, lim && i == (t[pos] - '0'));
            }

            if (!lim) f[pos] = ans;
            return ans;
        };

        long long a = dfs(dfs, 0, true);
        t = to_string(finish);
        memset(f, -1, sizeof(f));
        long long b = dfs(dfs, 0, true);
        return b - a;
    }
};
