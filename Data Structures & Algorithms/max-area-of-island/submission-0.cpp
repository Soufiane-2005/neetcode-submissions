class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {


        int area = 0;

        for(int i = 0 ;i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){

                if(grid[i][j]==1){
                    area = max(area, dfs(grid,i,j));
                }
            }
        }

        return area;
        
    }

    int dfs(vector<vector<int>>& grid, int i, int j){
        
       
        int n = grid.size();
        int m = grid[0].size();


        if(i<0 || i>=n || j<0 || j>=m)return 0;
        if(grid[i][j]!=1)return 0;
        
        grid[i][j]=-1;

        return 1+dfs(grid,i-1,j)+dfs(grid,i,j-1)+dfs(grid,i+1,j)+dfs(grid,i,j+1);

        
    }
};
