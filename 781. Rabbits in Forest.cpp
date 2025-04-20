// Problem: 781. Rabbits in Forest
// Difficulty: Medium
// Topic: Hash Table, Math, Counting
// Link: https://leetcode.com/problems/rabbits-in-forest
// Approach: Count how many times each answer appears. For each answer x, we group up to x+1 rabbits.
// If more than x+1 rabbits give the same answer, we need multiple groups.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for (int x : answers) {
            ++cnt[x];
        }
        int ans = 0;
        for (auto& [x, v] : cnt) {
            int group = x + 1;
            ans += (v + group - 1) / group * group;
        }
        return ans;
    }
};
