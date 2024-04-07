class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> stk;
        stk.push(-1); // Base for the first valid substring
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i); // New base for the next valid substring
                } else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }
        return maxLen;
    }
};
