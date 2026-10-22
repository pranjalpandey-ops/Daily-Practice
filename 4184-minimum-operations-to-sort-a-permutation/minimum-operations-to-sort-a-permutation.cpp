
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), z = 0;

        for (int i = 0; i < n; i++)
            if (nums[i] == 0) z = i;

        auto check = [&](int s) {
            for (int i = 1; i < n; i++) {
                int a = (z + (i - 1) * s + n) % n;
                int b = (z + i * s + n) % n;
                if (nums[a] > nums[b]) return false;
            }
            return true;
        };

        int ans = 1e9;

        if (check(1)) {
            ans = min(ans, z);
            ans = min(ans, n - z + 2);
        }

        if (check(-1)) {
            ans = min(ans, z + 2);
            ans = min(ans, n - z);
        }

        return ans == 1e9 ? -1 : ans;
    }
};
