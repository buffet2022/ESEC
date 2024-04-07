class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre_sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
        }

        int count = 0;
        unordered_map<int, int> m;
        m[0]++;
        for (int i = 1; i <= n; i++) {
            int sum = pre_sum[i] - k;
            if (m.count(sum)) {
                count += m[sum];
            }
            m[pre_sum[i]]++;
        }

        return count;
    }
};