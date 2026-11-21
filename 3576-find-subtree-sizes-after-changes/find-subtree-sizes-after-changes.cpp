
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n);
        vector<int> last(26, -1);

        function<void(int)> change = [&](int node) {
            int ch = s[node] - 'a';
            int old = last[ch];

            if (old != -1)
                newParent[node] = old;
            else
                newParent[node] = parent[node];

            last[ch] = node;

            for (int child : adj[node])
                change(child);

            last[ch] = old;
        };

        change(0);

        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        function<void(int)> dfs = [&](int node) {
            for (int child : tree[node]) {
                dfs(child);
                ans[node] += ans[child];
            }
        };

        dfs(0);

        return ans;
    }
};
