// Problem: 2179. Count Good Triplets in an Array
// Difficulty: Hard
// Topic: Binary Indexed Tree (Fenwick Tree), Coordinate Mapping
// Link: https://leetcode.com/problems/count-good-triplets-in-an-array
// Approach:
//   - Map each value in nums2 to its index for quick lookup
//   - Iterate through nums1, convert values to corresponding positions in nums2
//   - Use BIT to track number of elements less than current index (left count)
//   - Right count = total unseen elements to the right
//   - Multiply left * right to count valid triplets
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n), c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i + 1;

        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        long long ans = 0;

        for (int& num : nums1) {
            int p = pos[num];
            int left = tree->query(p);
            int right = n - p - (tree->query(n) - tree->query(p));
            ans += 1LL * left * right;
            tree->update(p, 1);
        }

        return ans;
    }
};
