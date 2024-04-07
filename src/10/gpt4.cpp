class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        vector<int> parent(2 * n);
        for (int i = 0; i < 2 * n; ++i) parent[i] = i;

        // Use std::function to declare the type of the lambda explicitly
        std::function<int(int)> find = [&](int x) -> int {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        for (int i = 0; i < n; ++i) {
            int a = find(row[2 * i]);
            int b = find(row[2 * i + 1]);
            if (a != b) parent[a] = b;
        }

        int swaps = 0;
        for (int i = 0; i < 2 * n; i += 2) {
            if (find(i) != find(i + 1)) {
                swaps++;
                parent[find(i)] = find(i + 1);
            }
        }
        return swaps;
    }
};