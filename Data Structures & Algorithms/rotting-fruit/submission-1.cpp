class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        int rowDirection[4] = {1, -1, 0, 0};
        int colDirection[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int size = q.size();
            bool rotten = false;
            for (int l = 0; l < size; l++) {
                pair<int, int> p = q.front();
                q.pop();
                int& row = p.first;
                int& col = p.second;

                for (int i = 0; i < 4; i++) {
                    int nextRow = row + rowDirection[i];
                    int nextCol = col + colDirection[i];
                    if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m) continue;

                    if (grid[nextRow][nextCol] == 1) {
                        rotten=true;
                        grid[nextRow][nextCol] = 2;
                        q.push({nextRow, nextCol});
                    }
                }
            }

            if(rotten)result++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return result;
    }
};
