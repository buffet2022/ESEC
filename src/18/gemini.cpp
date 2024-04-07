class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 按宽度升序排序，如果宽度相同，则按高度降序排序
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? b[1] > a[1] : a[0] < b[0];
        });

        // 使用树形背包dp[i]表示以第i个信封结尾的最长“俄罗斯套娃”信封的个数
        vector<int> dp(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // 宽度和高度都比当前信封大的信封才能套入
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};
