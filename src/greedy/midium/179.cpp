
// 179. 最大数
// 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 
// 示例 1：
// 输入：nums = [10,2]输出："210"
// 示例 2：
// 输入：nums = [3,30,34,5,9]输出："9534330"
 
// 提示：
// - 1 <= nums.length <= 100
// - 0 <= nums[i] <= 10(9)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        string res;
        for (string str : strs) {
            res += str;
        }
        if (res[0] == '0') {
            return "0";
        }
        return res;
    }
};