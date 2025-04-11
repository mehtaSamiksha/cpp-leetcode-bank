// Problem: 22. Generate Parentheses
// Difficulty: Medium
// Topic: Backtracking, Recursion
// Link: https://leetcode.com/problems/generate-parentheses
// Approach: Use DFS with backtracking. Maintain counts of left and right parentheses.
//           Add '(' if left > 0, add ')' if right > left.
// Time Complexity: O(4^n / sqrt(n)), Catalan number complexity
// Space Complexity: O(n) recursion depth and output space

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    dfs(n, n, "", ans);
    return ans;
  }

 private:
  void dfs(int l, int r, string&& path, vector<string>& ans) {
    if (l == 0 && r == 0) {
      ans.push_back(path);
      return;
    }

    if (l > 0) {
      path.push_back('(');
      dfs(l - 1, r, std::move(path), ans);
      path.pop_back();
    }
    if (l < r) {
      path.push_back(')');
      dfs(l, r - 1, std::move(path), ans);
      path.pop_back();
    }
  }
};
