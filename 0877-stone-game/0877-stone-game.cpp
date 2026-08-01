class Solution {
public:
    int dp[500][500]={};
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int takeLeft  = piles[i] - dp[i + 1][j];
                int takeRight = piles[j] - dp[i][j - 1];
                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        return dp[0][n-1]>=0;
    }
};