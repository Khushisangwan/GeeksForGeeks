#include <bits/stdc++.h>
using namespace std;
// Count the number of paths from src to dest in a directed graph where edges are given in the form of a vector of pairs.
// demo change
// demo change 2
class Solution {
    public:
        // Helper function to perform DFS and count paths from curr to dest
        int dfs(int curr, int dest, vector<vector <int>>& adj, vector <int>& vis){
                if(curr == dest) return 1; // Reached destination, count as one path
                if(vis[curr] != -1) return vis[curr]; // Return cached result if already computed
                
                int cnt = 0;
                // Explore all neighbors of current node
                for(int nbr: adj[curr]){
                        cnt += dfs(nbr, dest, adj, vis); // Add paths from neighbor to destination
                }
                
                return vis[curr] = cnt; // Cache and return the result
        }

        // Main function to count number of paths from src to dest
        int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
                vector<vector <int>> adj(V); // Adjacency list for the graph
                vector <int> vis(V, -1);     // Memoization array to store results
                
                // Build the adjacency list from edge list
                for(auto edge: edges){
                        int u = edge[0];
                        int v = edge[1];
                        adj[u].push_back(v);
                }
                
                // Start DFS from source node
                return dfs(src, dest, adj, vis);
        }
};