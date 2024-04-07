class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        int n = envelopes.size();
        std::vector<int> dp(n, 1); // dp[i] 表示以第 i 个信封结尾的最长递增子序列的长度for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}
};