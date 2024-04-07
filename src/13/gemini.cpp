class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.length(), m = p.length();
        if (m > n) {
            return res;
        }

        // 统计 p 中每个字符出现的次数
        vector<int> p_cnt(26, 0);
        for (char c : p) {
            p_cnt[c - 'a']++;
        }

        // 统计滑动窗口中每个字符出现的次数
        vector<int> s_cnt(26, 0);
        for (int i = 0; i < m; i++) {
            s_cnt[s[i] - 'a']++;
        }

        // 判断滑动窗口是否满足条件
        if (p_cnt == s_cnt) {
            res.push_back(0);
        }

        // 滑动窗口
        for (int i = m; i < n; i++) {
            // 移除旧字符
            s_cnt[s[i - m] - 'a']--;
            // 添加新字符
            s_cnt[s[i] - 'a']++;

            // 判断滑动窗口是否满足条件
            if (p_cnt == s_cnt) {
                res.push_back(i - m + 1);
            }
        }

        return res;
    }
};