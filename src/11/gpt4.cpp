class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); // Initialize parent array

        function<int(int)> find = [&](int x) {
            return x == parent[x] ? x : parent[x] = find(parent[x]);
        };

        auto isSimilar = [](const string& a, const string& b) {
            int diffCount = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != b[i] && ++diffCount > 2) return false;
            }
            return true;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (find(i) != find(j) && isSimilar(strs[i], strs[j])) {
                    parent[find(i)] = find(j);
                }
            }
        }

        int groups = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) ++groups;
        }

        return groups;
    }
};
