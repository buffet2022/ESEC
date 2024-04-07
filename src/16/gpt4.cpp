class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // 使用while循环是因为交换过来的新值可能还需要再次交换
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1; // 找到第一个不在正确位置上的数
            }
        }

        return n + 1; // 如果都正确，则缺失的是n+1
    }
};