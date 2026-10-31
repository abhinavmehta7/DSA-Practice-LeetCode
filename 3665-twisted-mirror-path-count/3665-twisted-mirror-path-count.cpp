class Solution {
public:
    static constexpr int mat[2][2][2] = {{{1, 1}, {1, 1}}, {{0, 1}, {1, 0}}};
    static constexpr int MOD = 1000000007;
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid[0].size(), left = 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < grid.size(); i++) {
            left = 0;
            for (int j = 0; j < n; j++) {
                int c = grid[i][j], top = dp[j];
                dp[j] = (left * mat[c][1][0] + top * mat[c][1][1]) % MOD;
                left  = (left * mat[c][0][0] + top * mat[c][0][1]) % MOD;
            }
        }
        return left;
    }
};