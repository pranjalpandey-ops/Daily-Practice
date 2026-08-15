class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0, n = nums.size();
        for (int a : nums)
           x ^= a;

        if (x != 0) return n;

        for (int a : nums)
            if (a != 0) return n - 1;

        return 0;
    }
};