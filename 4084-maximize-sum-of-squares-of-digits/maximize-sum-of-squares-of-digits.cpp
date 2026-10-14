
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) return "";

        string ans = "";

        for (int i = 0; i < num; i++) {
            int d = min(9, sum);
            ans += char('0' + d);
            sum -= d;
        }

        return ans;
    }
};
