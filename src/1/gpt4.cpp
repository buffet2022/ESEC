class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            if (i == 0 || nums[i - 1] != nums[i]) { // 避免重复
                twoSumII(nums, i, res);
            }
        }
        return res;
    }

    void twoSumII(const vector<int>& nums, int i, vector<vector<int>>& res) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                ++left;
            } else if (sum > 0) {
                --right;
            } else {
                res.push_back({nums[i], nums[left], nums[right]});
                ++left;
                --right;
                while (left < right && nums[left] == nums[left - 1]) // 跳过重复值
                    ++left;
                while (left < right && nums[right] == nums[right + 1]) // 跳过重复值
                    --right;
            }
        }
    }
};