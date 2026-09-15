class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), ans = 0, last = -1;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                if (s[i] == s[j] && (j - i < 2 || dp[i+1][j-1]))
                    dp[i][j] = 1;

        for (int j = 0; j < n; j++) {
            for (int i = last + 1; i <= j-k+1; i++) {
                if (dp[i][j]) {
                    ans++;
                    last = j;
                    break;
                }
            }
        }

        return ans;
    }
};