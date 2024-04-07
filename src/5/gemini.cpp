class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // 找到第一个递减的元素
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 若不存在递减元素，则说明当前排列为最大排列，需要翻转整个数组
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 找到第一个比 nums[i] 大的元素
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }

        // 交换 nums[i] 和 nums[j]
        swap(nums[i], nums[j]);

        // 翻转 nums[i + 1] 到结尾的元素
        reverse(nums.begin() + i + 1, nums.end());
    }
};