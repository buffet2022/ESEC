class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int s_len = s.length(), p_len = p.length();
        if (s_len < p_len) return result;

        unordered_map<char, int> p_freq, window;

        // 统计字符串 p 中每个字符的出现次数
        for (char c : p)
            p_freq[c]++;

        int left = 0, right = 0, match_count = 0;

        while (right < s_len) {
            char right_char = s[right];
            // 右指针扩展窗口
            if (p_freq.count(right_char)) {
                window[right_char]++;
                if (window[right_char] == p_freq[right_char])
                    match_count++;
            }
            right++;

            // 当窗口大小等于 p 的长度时，进行判断
            if (right - left == p_len) {
                // 如果当前窗口内字符出现次数与 p 的哈希表相匹配，则找到一个异位词
                if (match_count == p_freq.size())
                    result.push_back(left);

                char left_char = s[left];
                // 左指针缩小窗口
                if (p_freq.count(left_char)) {
                    if (window[left_char] == p_freq[left_char])
                        match_count--;
                    window[left_char]--;
                }
                left++;
            }
        }

        return result;
    }
};