
// 420. 强密码检验器
// 困难
// 相关标签
// 相关企业
// 满足以下条件的密码被认为是强密码：
// - 由至少 6 个，至多 20 个字符组成。
// - 包含至少 一个小写 字母，至少 一个大写 字母，和至少 一个数字 。
// - 不包含连续三个重复字符 (比如 "Baaabb0" 是弱密码, 但是 "Baaba0" 是强密码)。
// 给你一个字符串 password ，返回 将 password 修改到满足强密码条件需要的最少修改步数。如果 password 已经是强密码，则返回 0 。
// 在一步修改操作中，你可以：
// - 插入一个字符到 password ，
// - 从 password 中删除一个字符，或
// - 用另一个字符来替换 password 中的某个字符。
 
// 示例 1：
// 输入：password = "a"
// 输出：5
// 示例 2：
// 输入：password = "aA1"
// 输出：3
// 示例 3：
// 输入：password = "1337C0d3"
// 输出：0
 
// 提示：
// - 1 <= password.length <= 50
// - password 由字母、数字、点 '.' 或者感叹号 '!' 组成

//解答错误：
//输入
// password =
// "aaa111"

// 输出
// 1
// 预期结果
// 2


class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        int lower = 1, upper = 1, digit = 1;
        vector<int> repeat;
        int i = 0;
        while (i < n) {
            if (islower(password[i])) {
                lower = 0;
            } else if (isupper(password[i])) {
                upper = 0;
            } else if (isdigit(password[i])) {
                digit = 0;
            }
            int j = i;
            while (i < n && password[i] == password[j]) {
                i++;
            }
            repeat.push_back(i - j);
        }
        int missing = lower + upper + digit;
        if (n < 6) {
            return max(missing, 6 - n);
        }
        int over = max(n - 20, 0);
        int add = 0, del = 0;
        for (int k = 1; k < 3; k++) {
            for (int i = 0; i < repeat.size() && over > 0; i++) {
                if (repeat[i] < 3 || repeat[i] % 3 != k - 1) {
                    continue;
                }
                repeat[i] -= k;
                over -= k;
            }
        }
        for (int i = 0; i < repeat.size(); i++) {
            if (over > 0 && repeat[i] >= 3) {
                int need = repeat[i] - 2;
                repeat[i] -= over;
                over -= need;
            }
            if (repeat[i] >= 3) {
                add += repeat[i] / 3;
            }
        }
        for (int i = 0; i < repeat.size(); i++) {
            if (repeat[i] >= 3 && over > 0) {
                int need = repeat[i] - 2;
                repeat[i] -= over;
                over -= need;
            }
            if (repeat[i] >= 3) {
                del += repeat[i] / 3;
            }
        }
        return max(missing, max(add, del)) + over;
    }
};