class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // 初始化栈，用于处理边界情况
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // 更新栈顶元素为当前索引
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};