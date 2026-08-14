class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, ans = 0;
        map<char, int> mp;

        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;

            while (mp[s[r]] > 2) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};