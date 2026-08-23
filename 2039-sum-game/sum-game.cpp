class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int L = 0, R = 0, a = 0, b = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') a++;
            else L += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') b++;
            else R += num[i] - '0';
        }

        if ((a + b) % 2) return true;

        return 2 * (L - R) != -9 * (a - b);
    }
};