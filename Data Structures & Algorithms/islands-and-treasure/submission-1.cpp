class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            int& row = p.first;
            int& col = p.second;

            int rowDirection[4] = {1, -1, 0, 0};
            int colDirection[4] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int nextRow = row + rowDirection[i];
                int nextCol = col + colDirection[i];

                if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m) continue;

                if (grid[nextRow][nextCol] == INT_MAX) {
                    grid[nextRow][nextCol] = grid[row][col] + 1;
                    q.push({nextRow, nextCol});
                }
            }
        }
    }
};
