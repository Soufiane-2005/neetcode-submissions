class Solution {

    struct TrieNode {
        TrieNode* children[26]={};
        bool endword = false;
    };

    TrieNode* root = new TrieNode();


    void insert(const string& word){
        TrieNode* curr = root;
        for(char ch : word){
            int ind = ch - 'a';

            if(!curr->children[ind])curr->children[ind]=new TrieNode();
            curr = curr->children[ind];
        }

        curr->endword=true;
    }

    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* curr, vector<string>& result, string& path){

        
        if(!curr || row<0 || row>=board.size() || col<0 || col>=board[row].size() || board[row][col]=='#')return;
      
        int ind = board[row][col]-'a';

        if(!curr->children[ind])return;

        

        path.push_back(board[row][col]);
        char a = '#';
        swap(board[row][col],a);

        curr = curr->children[ind];

        if(curr->endword){
            result.push_back(path);
            curr->endword = false;
        }
       


        dfs(board,row-1,col,curr,result,path);
        dfs(board,row+1,col,curr,result,path);
        dfs(board,row,col-1,curr,result,path);
        dfs(board,row,col+1,curr,result,path);

        swap(board[row][col],a);
        path.pop_back();

    }

    



public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        
        for(const string& word : words){
            this->insert(word);
        }

        vector<string> result;
        string path ; 

        for(int i = 0 ; i<(int)board.size(); i++){
            for(int j = 0 ; j<(int)board[i].size(); j++){
                dfs(board,i,j,root,result,path);
            }
        }

        return result;

       
            
           
       
       
        
    }

  

        
    
};
