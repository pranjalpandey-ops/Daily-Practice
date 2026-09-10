class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        for (int i = 0; i < n; i++) {
            int left = (startIndex - i + n) % n;
            int right = (startIndex + i) % n;

            if (words[left] == target)
                return i;

            if (words[right] == target)
                return i;
        }

        return -1;
    }
};