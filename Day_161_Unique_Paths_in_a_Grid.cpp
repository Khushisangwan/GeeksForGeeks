class Solution {
  public:
    int solve(int n, int m, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i >= n || j >= m || grid[i][j])
    {
        return 0;
    }
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = solve(n, m, i, j + 1, grid, dp);
    int down = solve(n, m, i + 1, j, grid, dp);
    return dp[i][j] = right + down;
}
int uniquePaths(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n, m, 0, 0, grid, dp);
}
};