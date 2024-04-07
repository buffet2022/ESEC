class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        vector<string> result;

        // Build the graph
        for (const auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        // Start DFS from JFK
        dfs("JFK", graph, result);

        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());

        return result;
    }

private:
    void dfs(const string& airport, unordered_map<string, multiset<string>>& graph, vector<string>& result) {
        while (!graph[airport].empty()) {
            string nextAirport = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(nextAirport, graph, result);
        }
        result.push_back(airport);
    }
};
