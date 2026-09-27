class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        

        unordered_set<int> column;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        vector<vector<string>> result;

        vector<string> board;


        backtracking(board,0,column,diag1,diag2,n,result);

        return result;


        
    }


    void backtracking(vector<string>& board,int row, unordered_set<int>& column, unordered_set<int>& diag1, unordered_set<int>& diag2,int n, vector<vector<string>>& result){

        if((int)board.size()==n){
            result.push_back(board);
            return;
        }

        string path(n,'.');
        for(int i = 0 ; i<n; i++){
            if(column.contains(i) || diag1.contains(i+row) || diag2.contains(i-row))continue;
            path[i]='Q';
            column.insert(i);
            diag1.insert(i+row);
            diag2.insert(i-row);
            board.push_back(path);
            backtracking(board,row+1,column,diag1,diag2,n,result);
            path[i]='.';
            column.erase(i);
            diag1.erase(i+row);
            diag2.erase(i-row);
            board.pop_back();
        }




       
    }
};
