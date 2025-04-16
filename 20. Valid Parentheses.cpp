// Problem: 20. Valid Parentheses
// Difficulty: Easy
// Topic: Stack, String
// Link: https://leetcode.com/problems/valid-parentheses
// Approach:
//   - Use a stack to track opening brackets
//   - Push opening brackets onto the stack
//   - On encountering a closing bracket, check if it matches the top of the stack
//   - If not, the string is invalid
//   - At the end, the stack should be empty
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push_back(c);
            else if (stk.empty() || !match(stk.back(), c))
                return false;
            else
                stk.pop_back();
        }
        return stk.empty();
    }

    bool match(char l, char r) {
        return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
    }
};
