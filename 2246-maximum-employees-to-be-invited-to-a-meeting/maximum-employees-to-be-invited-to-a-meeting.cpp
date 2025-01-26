#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        
        // Step 1: Find all cycles using Kahn's Algorithm
        vector<int> in_degree(n, 0);
        for(int i=0; i<n; ++i){
            in_degree[favorite[i]]++;
        }
        
        queue<int> q;
        // Initialize queue with nodes having in-degree 0
        for(int i=0; i<n; ++i){
            if(in_degree[i] == 0){
                q.push(i);
            }
        }
        
        // Remove nodes not in any cycle
        while(!q.empty()){
            int u = q.front(); q.pop();
            int v = favorite[u];
            in_degree[v]--;
            if(in_degree[v] == 0){
                q.push(v);
            }
        }
        
        // At this point, nodes with in_degree >0 are part of cycles
        // Identify mutual pairs (cycles of length 2)
        // and other cycles
        vector<pair<int, int>> mutualPairs;
        int maxCycleSize = 0;
        vector<bool> visited(n, false);
        
        for(int i=0; i<n; ++i){
            if(in_degree[i] > 0 && !visited[i]){
                // Detect the cycle starting from node i
                vector<int> cycle;
                int current = i;
                while(!visited[current]){
                    visited[current] = true;
                    cycle.push_back(current);
                    current = favorite[current];
                }
                
                if(cycle.size() == 2 && favorite[cycle[1]] == cycle[0]){
                    // It's a mutual pair
                    mutualPairs.emplace_back(cycle[0], cycle[1]);
                }
                else{
                    // It's a cycle of length >2
                    maxCycleSize = max(maxCycleSize, (int)cycle.size());
                }
            }
        }
        
        // Step 2: For mutual pairs, find the longest chains leading to each member
        // Build reverse adjacency list
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<n; ++i){
            adj[favorite[i]].push_back(i);
        }
        
        // To store maximum chain length leading to each member of mutual pairs
        // Initialize to 0
        vector<int> maxChainForPair(mutualPairs.size() * 2, 0);
        
        // Function to find the maximum depth starting from a node, excluding the mutual pair other member
        // We use memoization to store the maximum chain lengths
        // To prevent overlapping computations, we mark mutual pair members and skip them in DFS
        // except for their own respective pair
        // Since mutual pairs do not form cycles outside themselves,
        // we can safely perform DFS from each node not in a cycle or mutual pair to find the longest chain
        // that can be appended to each mutual pair member.
        
        // To optimize, we'll precompute the maximum depth for each node using DFS
        // and then assign them to the respective mutual pair members.
        
        // We'll exclude nodes that are part of any cycle (already handled)
        // because chains leading to mutual pairs should not contain cycles.
        
        // To store the maximum chain lengths leading to each node
        vector<int> maxDepth(n, -1);
        
        // Function to compute maximum depth via DFS with memoization
        function<int(int)> dfs = [&](int node) -> int {
            if(maxDepth[node] != -1){
                return maxDepth[node];
            }
            maxDepth[node] = 0;
            for(auto &neighbor : adj[node]){
                // Exclude the mutual pair setup
                maxDepth[node] = max(maxDepth[node], 1 + dfs(neighbor));
            }
            return maxDepth[node];
        };
        
        // Calculate maximum chains for mutual pairs
        int totalMutualPairsContribution = 0;
        for(auto &p : mutualPairs){
            // For p.first, find the maximum chain length ending at p.first, excluding p.second
            // Similarly for p.second, exclude p.first
            // To exclude, we temporarily set favorite[p.first] = -1 and favorite[p.second] = -1
            // but since mutual pairs are handled separately, we can treat them as an end
            
            // To prevent chains from including the mutual pair other member,
            // we can traverse the adjacency list but skip the mutual pair other member
            // when expanding the chain
            
            // Implement a helper lambda to compute the maximum chain leading to a specific node
            auto computeChain = [&](int target, int exclude) -> int {
                // Use DFS from target's neighbors, excluding 'exclude'
                int maxChain = 0;
                for(auto &neighbor : adj[target]){
                    if(neighbor == exclude){
                        continue;
                    }
                    // Compute the depth from this neighbor
                    maxChain = max(maxChain, 1 + dfs(neighbor));
                }
                return maxChain;
            };
            
            int chain1 = computeChain(p.first, p.second);
            int chain2 = computeChain(p.second, p.first);
            totalMutualPairsContribution += 2 + chain1 + chain2;
        }
        
        // The answer is the maximum between the largest cycle and the total mutual pairs contribution
        return max(maxCycleSize, totalMutualPairsContribution);
    }
};