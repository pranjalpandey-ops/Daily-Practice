class Solution {
public:
    vector<vector<string>> ans;

    bool check(vector<string>& b, int r, int c, int n) {
        for (int i = 0; i < r; i++)
            if (b[i][c] == 'Q')
                return false;

        for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--)
            if (b[i][j] == 'Q')
                return false;

        for (int i = r-1, j = c+1; i >= 0 && j < n; i--, j++)
            if (b[i][j] == 'Q')
                return false;

        return true;
    }

    void solve(vector<string>& b, int row, int n) {
        if (row == n) {
            ans.push_back(b);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (check(b, row, col, n)) {
                b[row][col] = 'Q';
                solve(b, row + 1, n);
                b[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> b(n, string(n, '.'));
        solve(b, 0, n);
        return ans;
    }
};