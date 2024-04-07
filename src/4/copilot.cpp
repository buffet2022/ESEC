class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希表存储字符及其最近出现的位置
        unordered_map<char, int> char_map;
        int left = 0, right = 0, max_len = 0;

        while (right < s.size()) {
            char c = s[right];

            // 更新字符最近出现的位置
            char_map[c] = right;

            // 判断是否出现重复字符
            if (char_map.count(c) > 0 && char_map[c] >= left) {
                // 更新滑动窗口左边界
                left = char_map[c] + 1;
            }

            // 更新最长子串长度
            max_len = max(max_len, right - left + 1);

            // 扩大滑动窗口右边界
            right++;
        }

        return max_len;
    }
};