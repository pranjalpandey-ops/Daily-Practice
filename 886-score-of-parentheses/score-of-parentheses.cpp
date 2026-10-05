class Solution {
public:
    int scoreOfParentheses(string s) {
        int a = 0;
        int h = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                h++;
            } else {
                h--;
                if (s[i - 1] == '(') {
                    a += 1 << h;
                }
            }
        }

        return a;
    }
};