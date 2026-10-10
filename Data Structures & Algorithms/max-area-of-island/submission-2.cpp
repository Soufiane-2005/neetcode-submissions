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

    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        stack<pair<int, int>> st;

        int area = 0;
        grid[i][j] = 0;
        st.push({i, j});
        while (!st.empty()) {
            pair<int, int> p = st.top();
            st.pop();
            int& row = p.first;
            int& col = p.second;

            int rowDirection[4] = {1, -1, 0, 0};
            int colDirection[4] = {0, 0, 1, -1};

            for (int k = 0; k < 4; k++) {
                int nextRow = row + rowDirection[k];
                int nextCol = col + colDirection[k];
                if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m ||
                    grid[nextRow][nextCol] == 0)
                    continue;
                grid[nextRow][nextCol] = 0;
                st.push({nextRow, nextCol});
            }
            area++;
        }

        return area;
    }
};
