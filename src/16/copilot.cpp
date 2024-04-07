class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        // 将所有负数和大于 n 的数置为 n+1for (int& num : nums) {
        if (num <= 0 || num > n) {
            num = n + 1;
        }
    }

    // 遍历数组，将出现的正整数对应的位置标记为负数for (int num : nums) {
    int idx = std::abs(num) - 1;
    if (idx >= 0 && idx < n) {
        nums[idx] = -std::abs(nums[idx]);
    }
}

// 找到第一个正数对应的位置for (int i = 0; i < n; ++i) {
if (nums[i] > 0) {
return i + 1;
}
}

// 如果都是负数或者大于 n 的数，返回 n+1return n + 1;
}
};