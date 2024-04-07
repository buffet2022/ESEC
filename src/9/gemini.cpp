class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 构建邻接表
        unordered_map<string, vector<string>> adj;
        for (const vector<string>& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        // 对邻接表进行排序
        for (auto& it : adj) {
            sort(it.second.begin(), it.second.end());
        }

        vector<string> res;
        dfs(adj, "JFK", res);
        return res;
    }

private:
    void dfs(unordered_map<string, vector<string>>& adj, string cur, vector<string>& res) {
        res.push_back(cur);

        for (string& next : adj[cur]) {
            // 递归遍历所有可达的节点
            if (!adj[next].empty()) {
                dfs(adj, next, res);
            }
        }

        // 删除所有已经遍历过的节点
        adj[cur].clear();
    }
};