class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;

        vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) {
            pCount[c - 'a']++;
        }

        int left = 0, right = 0;
        while (right < s.length()) {
            sCount[s[right] - 'a']++;

            // 当窗口大小等于p的长度时，比较两个数组是否相等
            if (right - left + 1 == p.length()) {
                if (pCount == sCount) {
                    result.push_back(left);
                }
                sCount[s[left] - 'a']--; // 移动窗口
                left++;
            }
            right++;
        }
        return result;
    }
};