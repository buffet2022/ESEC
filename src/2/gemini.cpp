class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 哈希表存储元素及其对应的下标
        unordered_map<int, int> hash_table;

        // 遍历数组
        for (int i = 0; i < nums.size(); ++i) {
            // 检查哈希表中是否存在另一个元素使其满足条件
            int complement = target - nums[i];
            if (hash_table.count(complement) > 0 && hash_table[complement] != i) {
                return {i, hash_table[complement]};
            }

            // 将当前元素放入哈希表
            hash_table[nums[i]] = i;
        }

        // 未找到满足条件的元素
        return {};
    }
};