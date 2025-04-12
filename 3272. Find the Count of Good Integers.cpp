// Problem: 3272. Find the Count of Good Integers
// Difficulty: Hard
// Topic: Math, Permutations, Palindromes, Factorials
// Link: https://leetcode.com/problems/find-the-count-of-good-integers
// Approach: 
//   1. Generate all palindromic numbers of length n.
//   2. Filter those divisible by k.
//   3. Count unique permutations avoiding duplicates by using a set and factorials.
// Time Complexity: O(10^(n/2) * n), due to palindrome generation and permutation count
// Space Complexity: O(10^(n/2) + n), for set and factorial array

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<long long> fac(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * i;
        }

        long long ans = 0;
        unordered_set<string> vis;
        int base = pow(10, (n - 1) / 2);

        for (int i = base; i < base * 10; ++i) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            s += rev.substr(n % 2);
            if (stoll(s) % k) {
                continue;
            }
            string t = s;
            sort(t.begin(), t.end());
            if (vis.count(t)) {
                continue;
            }
            vis.insert(t);
            vector<int> cnt(10);
            for (char c : t) {
                cnt[c - '0']++;
            }
            long long res = (n - cnt[0]) * fac[n - 1];
            for (int x : cnt) {
                res /= fac[x];
            }
            ans += res;
        }
        return ans;
    }
};
