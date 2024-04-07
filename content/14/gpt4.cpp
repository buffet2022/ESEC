class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0; // 用于计算前缀和
        unordered_map<int, int> prefixSums; // 前缀和 -> 出现次数
        prefixSums[0] = 1; // 初始化，和为0的子数组默认出现一次

        for (int num : nums) {
            sum += num;
            // 如果存在当前sum-k的前缀和，表示找到符合条件的子数组
            if (prefixSums.find(sum - k) != prefixSums.end()) {
                count += prefixSums[sum - k];
            }
            // 更新当前和的出现次数
            prefixSums[sum]++;
        }

        return count;
    }
};