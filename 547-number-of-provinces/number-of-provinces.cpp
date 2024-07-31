class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited,
             int u) {
        visited[u] = true;
        for (auto& v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, visited, v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        int n = isConnected.size();
        // make graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // dfs calling
        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};