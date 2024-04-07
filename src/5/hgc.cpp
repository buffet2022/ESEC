class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k=nums.size()-1;
        while(k>0 && nums[k-1]>=nums[k]) k--;
        if(k<=0){   //特判：此时序列是最大的一个排列
            reverse(nums.begin(),nums.end());  // 此时序列递减，翻转即可
        }
        else{
            int t=k;
            while(t<nums.size() && nums[t]>nums[k-1]) t++; // 找到向高位递减的临界点
            swap(nums[k-1],nums[t-1]); //  找到该递减序列中大于nums[k-1]的最小值，并交换
            reverse(nums.begin()+k,nums.end());  // 对该递减序列翻转，方成为最小排列
        }

    }
};