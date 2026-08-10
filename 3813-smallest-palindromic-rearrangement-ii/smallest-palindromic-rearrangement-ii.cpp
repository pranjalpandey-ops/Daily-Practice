#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    // Count distinct permutations of cnt.
    // We only need to know whether the answer reaches k.
    ll countWays(vector<int>& cnt, ll k) {
        int total = 0;

        for (int x : cnt) {
            total += x;
        }

        ll ways = 1;

        for (int i = 0; i < 26; i++) {
            int x = cnt[i];

            if (x == 0)
                continue;

            // Multiply by C(total, x)
            ll comb = 1;

            for (int j = 1; j <= x; j++) {
                __int128 value =
                    (__int128)comb * (total - x + j) / j;

                if (value >= k) {
                    comb = k;
                    break;
                }

                comb = (ll)value;
            }

            // ways *= comb, but stop once we reach k
            if ((__int128)ways * comb >= k) {
                return k;
            }

            ways *= comb;
            total -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        // Count characters.
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find the middle character.
        int middle = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = i;
                break;
            }
        }

        // Build frequency of the left half.
        vector<int> cnt(26, 0);

        for (int i = 0; i < 26; i++) {
            cnt[i] = freq[i] / 2;
        }

        int halfLength = s.length() / 2;

        // If there are fewer than k possible palindromes,
        // no answer exists.
        if (countWays(cnt, k) < k) {
            return "";
        }

        string left;

        // Construct the left half character by character.
        for (int pos = 0; pos < halfLength; pos++) {

            // Try characters from 'a' to 'z'.
            for (int c = 0; c < 26; c++) {

                if (cnt[c] == 0) {
                    continue;
                }

                // Temporarily place this character.
                cnt[c]--;

                // Count permutations with this character fixed.
                ll ways = countWays(cnt, k);

                if (ways >= k) {
                    // The k-th permutation starts with this character.
                    left.push_back(char('a' + c));
                    break;
                }

                // All these permutations come before our answer.
                k -= ways;

                // Restore the character.
                cnt[c]++;
            }
        }

        // The right half is the reverse of the left half.
        string right = left;
        reverse(right.begin(), right.end());

        // Construct final palindrome.
        if (middle != -1) {
            return left + char('a' + middle) + right;
        }

        return left + right;
    }
};