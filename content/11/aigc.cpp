class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n); // 并查集的父节点数组
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // 初始化每个字符串的父节点为自身
        }

        // 判断两个字符串是否相似
        auto isSimilar =  {
                int diff = 0;
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] != b[i]) {
                        ++diff;
                        if (diff > 2) return false; // 最多只能有两个不同字符
                    }
                }
                return true;
        };

        // 合并相似字符串
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    int root_i = find(parent, i);
                    int root_j = find(parent, j);
                    if (root_i != root_j) {
                        parent[root_i] = root_j; // 合并两个组
                    }
                }
            }
        }

        // 统计不同组的数量
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                ++result;
            }
        }
        return result;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]); // 路径压缩
        }
        return parent[x];
    }
};
