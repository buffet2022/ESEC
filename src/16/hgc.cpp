class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), ans = n + 1;
        auto judge = [&](int x){return x >= 1 && x <= n;};
        for(int& m : nums){
            if(!judge(m)) m = 0;
        }
        for(int i = 0; i < n; i ++){
            if(nums[i] > 0){
                int t = nums[i];
                nums[i] = 0;
                while(t > 0){
                    int x = nums[t - 1];
                    nums[t - 1] = -1;
                    t = x;
                }
            }
        }
        for(int i = 0; i < n; i ++){
            if(nums[i] != -1){
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};
