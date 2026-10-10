class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    area = max(area, dfs(grid, i, j, n, m));
                }
            }
        }

        return area;
    }

    int dfs(vector<vector<int>>& grid, int i, int j,int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return 0;

        grid[i][j] = 0;

        return 1 + dfs(grid, i + 1, j, n, m) +
               dfs(grid, i, j + 1, n, m) +
               dfs(grid, i - 1, j, n, m) +
               dfs(grid, i, j - 1, n, m);
    }
};
