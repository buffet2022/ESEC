class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // 存储每个数及其索引
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                // 如果找到complement，并且它的索引不是i，则返回结果
                return {numMap[complement], i};
            }
            // 没找到则将当前数和其索引存入哈希表
            numMap[nums[i]] = i;
        }
        return {}; // 根据题意，这行代码不会执行，因为总会找到解
    }
};