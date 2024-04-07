class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; // Empty pattern matches empty string

        // Handles patterns like a*, a*b*, a*b*c* etc.
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || // Match 0 times
                               (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')); // Match 1 or more times
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        return dp[m][n];
    }
};
