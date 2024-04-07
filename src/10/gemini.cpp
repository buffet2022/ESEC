class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        // 并查集
        UnionFind uf(n);

        for (int i = 0; i < n; i++) {
            // 将情侣的根节点合并
            uf.unionSet(row[i] / 2, row[i + n] / 2);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            // 如果当前位置不是情侣的位置
            if (row[i] != row[i + n]) {
                // 找到情侣的根节点
                int root1 = uf.findSet(row[i] / 2);
                int root2 = uf.findSet(row[i + n] / 2);
                // 如果两个根节点不同，则需要交换
                if (root1 != root2) {
                    ans++;
                }
            }
        }

        return ans;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n) {
            parents = vector<int>(n);
            ranks = vector<int>(n);
            for (int i = 0; i < n; i++) {
                parents[i] = i;
                ranks[i] = 0;
            }
        }

        void unionSet(int x, int y) {
            int rootX = findSet(x);
            int rootY = findSet(y);
            if (rootX == rootY) {
                return;
            }

            if (ranks[rootX] < ranks[rootY]) {
                parents[rootX] = rootY;
            } else if (ranks[rootX] > ranks[rootY]) {
                parents[rootY] = rootX;
            } else {
                parents[rootY] = rootX;
                ranks[rootX]++;
            }
        }

        int findSet(int x) {
            if (parents[x] != x) {
                parents[x] = findSet(parents[x]);
            }

            return parents[x];
        }

    private:
        vector<int> parents;
        vector<int> ranks;
    };
};
