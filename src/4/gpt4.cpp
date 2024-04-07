class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap; // 字符及其最后出现位置的映射
        int maxLength = 0;
        for (int start = 0, end = 0; end < s.length(); ++end) {
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                start = max(charIndexMap[s[end]] + 1, start); // 更新起始位置
            }
            charIndexMap[s[end]] = end; // 更新字符的最新位置
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
