class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        std::unordered_map<char, int> chars; // 用于存储 p 中每个字符的出现次数
        int head = 0, tail = 0; // 双指针，head 指向子串的头元素，tail 指向子串的尾元素的下一个元素位置

        // 初始化 chars 数组
        for (char c : p) {
            chars[c]++;
        }

        // 遍历字符串 s
        while (tail < s.length()) {
            // 如果 tail 指向的字符在 chars 中对应的值大于 0，则执行减 1 操作，并且执行 tail++
            if (chars[s[tail]] > 0) {
                chars[s[tail++]]--;
                // 如果 tail 减去 head 等于 p 的长度，说明找到了 p 的异位词子串
                if (tail - head == p.length()) {
                    result.push_back(head);
                }
            } else {
                // 否则，获得 head 指向的字符，然后针对该字符在 chars 数组中的位置处执行加 1 操作，并且执行 head++
                chars[s[head++]]++;
            }
        }

        return result;
    }
};