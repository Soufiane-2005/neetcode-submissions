class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int count=0;
        for(int i=0; i<grid.size(); i++){

            for(int j = 0; j<grid[i].size(); j++){

                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }

        
        return count;
        
    }

    void dfs(vector<vector<char>>& grid, int i , int j){

       

        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m)return;

        if(grid[i][j]!='1')return;

        if(grid[i][j]=='1')grid[i][j]='#';

        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);

        

    
    }
};
