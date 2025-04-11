// Problem: 1123. Lowest Common Ancestor of Deepest Leaves
// Difficulty: Medium
// Topic: Tree, DFS, Recursion
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves
// Approach: Use post-order DFS to return both depth and the LCA at the deepest level.
//           At each node, compare depths of left and right subtrees to decide LCA.
// Time Complexity: O(n), where n is the number of nodes in the tree
// Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<TreeNode*, int> {
            if (!root) return {nullptr, 0};

            auto [l, d1] = dfs(dfs, root->left);
            auto [r, d2] = dfs(dfs, root->right);

            if (d1 > d2) return {l, d1 + 1};
            if (d1 < d2) return {r, d2 + 1};
            return {root, d1 + 1};
        };

        return dfs(dfs, root).first;
    }
};
