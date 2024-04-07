class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }

        for (int i = 1; i <= n + 1; i++) {
            if (!s.count(i)) {
                return i;
            }
        }

        return -1;
    }
};