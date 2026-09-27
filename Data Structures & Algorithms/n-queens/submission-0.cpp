class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        

        vector<vector<int>> forbidden(n,vector<int>(n,1));

        vector<vector<string>> result;

        vector<string> board;


        backtracking(board,0,forbidden,n,result);

        return result;


        
    }


    void backtracking(vector<string>& board,int row, vector<vector<int>>& forbidden,int n, vector<vector<string>>& result){

        if(board.size()==n){
            result.push_back(board);
            return;
        }


        string path(n,'.');
        
        for(int i = 0 ; i<n; i++){
            bool isAvailable = forbidden[row][i]==1?true:false;
            if(!isAvailable)continue;
            path[i]='Q';
            // now we are at (row,i):
            for(int k = row+1; k<n; k++){
                int left = i - k + row;
                int right = i + k - row;
                if(left>=0){
                    forbidden[k][left]--;
                    
                }
                if(right<n){
                    forbidden[k][right]--;
                }
                forbidden[k][i]--;
                
            }
            board.push_back(path);
            backtracking(board,row+1,forbidden,n,result);
            board.pop_back();
            path[i]='.';
            for(int k = row+1; k<n; k++){
                int left = i - k + row;
                int right = i + k - row;
                if(left>=0){
                    forbidden[k][left]++;
                    
                }
                if(right<n){
                    forbidden[k][right]++;
                }
                forbidden[k][i]++;
                
            }
            
        }


       
    }
};
