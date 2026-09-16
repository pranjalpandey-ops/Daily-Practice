class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& a, int i, vector<int>& v) {
        ans.push_back(v);

        for(int j = i; j < a.size(); j++) {
            if(j > i && a[j] == a[j-1]) continue;

            v.push_back(a[j]);
            solve(a, j + 1, v);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<int> v;
        solve(a, 0, v);
        return ans;
    }
};