class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        vector<string> itinerary;
        // Construct the graph
        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        // Start the DFS from "JFK"
        dfs("JFK", graph, itinerary);
        // Since we add the airport when we backtrack, reverse the result to get the correct order
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

    void dfs(string airport, unordered_map<string, multiset<string>>& graph, vector<string>& itinerary) {
        while (!graph[airport].empty()) {
            string nextAirport = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin()); // Remove the edge
            dfs(nextAirport, graph, itinerary);
        }
        // Add the airport when we backtrack, ensuring we only add it once all of its edges are explored
        itinerary.push_back(airport);
    }
};
