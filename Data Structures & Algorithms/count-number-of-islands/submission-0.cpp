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
        int m = grid[i].size();
        grid[i][j]='#';
        stack<pair<int,int>> st;
        st.push({i,j});

        while(!st.empty()){

            pair<int,int> p = st.top();
            st.pop();
            int& row = p.first;
            int& col = p.second;

           int di[] = {-1, 0,1,0};
           int dj[] = {0,-1,0,1};

           for(int k = 0; k<4; k++){
            int ni = row + di[k];
            int nj = col + dj[k];

            if(ni>=0 && ni<n && nj>=0 && nj<m){
                if(grid[ni][nj]=='1'){
                    grid[ni][nj]='#';
                    st.push({ni,nj});
                }
            }

           }



        }
    }
};
