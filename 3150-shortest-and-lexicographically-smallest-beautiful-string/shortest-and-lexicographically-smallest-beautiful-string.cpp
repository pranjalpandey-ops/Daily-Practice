class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string a = "";

        for (int i = 0; i < s.size(); i++) {
            int c = 0;

            for (int j = i; j < s.size(); j++) {
                if (s[j] == '1')
                    c++;

                if (c == k) {
                    string t = s.substr(i, j - i + 1);

                    if (a == "" || t.size() < a.size() ||
                        (t.size() == a.size() && t < a)) {
                        a = t;
                    }

                    break;
                }
            }
        }

        return a;
    }
};