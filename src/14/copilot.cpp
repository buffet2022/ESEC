class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int count = 0; // 记录符合条件的子数组个数int preSum = 0; // 前缀和
        std::unordered_map<int, int> prefixSums; // 前缀和 -> 出现次数// 初始化前缀和为0的情况
        prefixSums[0] = 1;

        for (int num : nums) {
            preSum += num; // 计算当前位置的前缀和// 如果 preSum - k 在哈希表中，则答案个数累加上 prefixSums[preSum - k]if (prefixSums.find(preSum - k) != prefixSums.end()) {
            count += prefixSums[preSum - k];
        }

        // 更新哈希表
        prefixSums[preSum]++;
    }

    return count;
}
};