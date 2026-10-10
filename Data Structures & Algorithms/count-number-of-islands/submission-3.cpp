class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int number_of_islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    dfs(grid, i, j, n, m);
                    number_of_islands++;
                }
            }
        }

        return number_of_islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        stack<pair<int, int>> st;
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

                if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m) continue;
                if (grid[nextRow][nextCol] == '1') {
                    grid[nextRow][nextCol] = '0';
                    st.push({nextRow, nextCol});
                }
            }
        }
    }
};
