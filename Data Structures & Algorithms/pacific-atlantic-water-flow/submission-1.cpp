class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        vector<vector<bool>> pacific(n,vector<bool>(m,false));

        for(int i = 0 ; i<n; i++){
            dfsPacific(grid,pacific,i,0,n,m);
            dfsAtlantic(grid,atlantic,i,m-1,n,m);
        }

        for(int j = 0 ; j<m; j++){
            dfsPacific(grid,pacific,0,j,n,m);
            dfsAtlantic(grid,atlantic,n-1,j,n,m);
        }

        

        vector<vector<int>> result;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(atlantic[i][j] && pacific[i][j])result.push_back({i,j});
            }
        }

        return result;

        
        


        
    }

    void dfsPacific(vector<vector<int>>& grid, vector<vector<bool>>& pacific, int i , int j, int n , int m){
        pacific[i][j]=true;

        int rowDirection[4]={1,-1,0,0};
        int colDirection[4]={0,0,1,-1};

        for(int k = 0 ; k<4; k++){
            int nextRow = i + rowDirection[k];
            int nextCol = j + colDirection[k];

            if(nextRow<0 || nextCol<0 || nextRow>=n || nextCol>=m)continue;
            if(grid[nextRow][nextCol]<grid[i][j] || pacific[nextRow][nextCol])continue;
            dfsPacific(grid,pacific,nextRow,nextCol,n,m);
        }
        
    }


    void dfsAtlantic(vector<vector<int>>& grid, vector<vector<bool>>& atlantic, int i , int j, int n , int m){
        atlantic[i][j]=true;

        int rowDirection[4]={1,-1,0,0};
        int colDirection[4]={0,0,1,-1};

        for(int k = 0 ; k<4; k++){
            int nextRow = i + rowDirection[k];
            int nextCol = j + colDirection[k];

            if(nextRow<0 || nextCol<0 || nextRow>=n || nextCol>=m)continue;
            if(grid[nextRow][nextCol]<grid[i][j] || atlantic[nextRow][nextCol])continue;
            dfsAtlantic(grid,atlantic,nextRow,nextCol,n,m);
        }   
    }


    
};
