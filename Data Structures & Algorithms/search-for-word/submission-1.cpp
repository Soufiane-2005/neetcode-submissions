class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(size_t i = 0 ; i<board.size(); i++){
            for(size_t j = 0 ; j<board[0].size(); j++){
                if(dfs(board,word,i,j,0))return true;
            }
        }
        return false;
        
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j , int index){

        if(index==(int)word.size())return true;

        if(i<0 || j<0 || i>=(int)board.size() || j>=(int)board[0].size())return false;



        char saved = board[i][j];

        if(saved!=word[index])return false;

        board[i][j] = '#';

        bool found =  dfs(board,word,i+1,j,index+1) || dfs(board,word,i,j+1,index+1) || dfs(board,word,i-1,j,index+1) || dfs(board,word,i,j-1,index+1);

        board[i][j] = saved;

        return found;


        

       



        
    }

    
        

       
            

        
    
};
