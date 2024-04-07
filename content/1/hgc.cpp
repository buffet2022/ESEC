class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]>0)return result;//数组递增
            if(i>0&&nums[i]==nums[i-1]){
                continue; //对a去重，如果i=1与i=0对应的元素相同，那么跳过下面的所有操作，left,right不需要考虑了。
            }
            //a满足去重，再来确定left,right以及去除问题。
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){//当left==right时，b，c为同一个数，不符合要求。
                if(nums[i]+nums[left]+nums[right]<0) left++;
                else if(nums[i]+nums[left]+nums[right]>0) right--;
                else{
                    vector<int>v = {nums[i],nums[left],nums[right]};
                    result.push_back(v);
                    //下面考虑left，right的移动情况。
                    while (right > left && nums[right] == nums[right - 1])right--;
                    //再次加上right>left的原因是：进入上面的循环时是复合right>left的，但是
                    //可能在循环中 left与right发生改变。
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    //为什么是while?举个例子
                    //[0 -1 -1 -1 -1 -1 1 1 1 1 1 1 ]
                    //因为当i= 0时，left与right就已经收集到了正确的结果
                    //此时应该持续地移动left 与 right，一次是不够。


                    left++;
                    right--;
                    //是为了在找到一个有效的三元组后，将 left 和 right 分别向前和向后移动一位，以便在后续的循环中继续寻找其他可能的三元组。这样可以确保所有的有效三元组都被找到。
                }
            }
        }
        return result;

    }
};