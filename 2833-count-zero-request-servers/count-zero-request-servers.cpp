
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto a, auto b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        unordered_map<int, int> count;

        int left = 0, right = 0;

        for (auto [time, index] : q) {
            while (right < logs.size() && logs[right][1] <= time) {
                count[logs[right][0]]++;
                right++;
            }

            while (left < right && logs[left][1] < time - x) {
                count[logs[left][0]]--;

                if (count[logs[left][0]] == 0)
                    count.erase(logs[left][0]);

                left++;
            }

            ans[index] = n - count.size();
        }

        return ans;
    }
};
