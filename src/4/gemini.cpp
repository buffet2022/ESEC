
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, max_len = 0;
        int char_set[256] = {0}; // 记录字符出现次数

        while (right < s.size()) {
            char_set[s[right]]++;

            while (char_set[s[right]] > 1) {
                char_set[s[left]]--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
            right++;
        }

        return max_len;
    }
}