class Solution {
public:
    bool isValid(string s) {
        // 创建栈
        stack<char> stk;

        // 遍历字符串
        for (char c : s) {
            // 左括号入栈
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                // 右括号
                if (stk.empty()) {
                    return false;
                }

                char top = stk.top();
                if (c == ')' && top == '(' || c == ']' && top == '[' || c == '}' && top == '{') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        // 栈非空则说明括号未匹配
        return stk.empty();
    }
};