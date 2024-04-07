class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        int maxLen = 0;
        int left = -1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                    maxLen = max(maxLen, i - (st.empty() ? left : st.top()));
                } else {
                    left = i;
                }
            }
        }

        return maxLen;
    }
};