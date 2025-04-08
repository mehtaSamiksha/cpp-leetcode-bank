// Problem: 796. Rotate String
// Difficulty: Easy
// Topic: String, Simulation
// Link: https://leetcode.com/problems/rotate-string
// Approach: Check if s is a substring of goal + goal
// Time Complexity: O(n^2) in worst case due to string search
// Space Complexity: O(n)

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (goal.size() != s.size()) return false;
        goal = goal + goal;
        return goal.find(s) != -1;
    }
};
