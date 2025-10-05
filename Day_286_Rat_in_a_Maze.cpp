
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Recursive function to find all paths from current position to destination
        void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string path, vector<vector<int>> &vis) {
                // Base case: reached the destination (bottom-right corner)
                if(i == n - 1 && j == n - 1) {
                        ans.push_back(path);
                        return;
                }
                
                // Mark current cell as visited
                vis[i][j] = 1;
                
                // Move Down: check if valid position and not visited
                if(i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1) {
                        solve(i + 1, j, maze, n, ans, path + "D", vis);
                }
                
                // Move Left: check if valid position and not visited
                if(j - 1 >= 0 && !vis[i][j - 1] && maze[i][j - 1] == 1) {
                        solve(i, j - 1, maze, n, ans, path + "L", vis);
                }
                
                // Move Right: check if valid position and not visited
                if(j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1) {
                        solve(i, j + 1, maze, n, ans, path + "R", vis);
                }
                
                // Move Up: check if valid position and not visited
                if(i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1) {
                        solve(i - 1, j, maze, n, ans, path + "U", vis);
                }
                
                // Backtrack: unmark current cell as visited
                vis[i][j] = 0;
        }
        
        // Main function to find all possible paths in the maze
        vector<string> ratInMaze(vector<vector<int>>& maze) {
                int n = maze.size();
                vector<string> ans; // Store all valid paths
                vector<vector<int>> vis(n, vector<int>(n, 0)); // Visited array
                
                // Check if start and end positions are valid (value = 1)
                if(maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
                        solve(0, 0, maze, n, ans, "", vis);
                }
                
                return ans;
        }
};