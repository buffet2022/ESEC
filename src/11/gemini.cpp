class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(strs, i, visited);
                count++;
            }
        }
        return count;
    }

    void dfs(vector<string>& strs, int i, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < strs.size(); j++) {
            if (!visited[j] && isSimilar(strs[i], strs[j])) {
                dfs(strs, j, visited);
            }
        }
    }

    bool isSimilar(string& s1, string& s2) {
        int n = s1.length();
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
        }
        return diff <= 2;
    }
};