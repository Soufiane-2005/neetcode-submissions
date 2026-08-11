class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        

        vector<vector<char>>& v = board;
        
        // this is for testing the first two conditions:
        

        for(int i = 0 ; i<9; i++){
            unordered_map<char,bool> dict_row;
            unordered_map<char,bool> dict_column;
            
            for(int j = 0 ; j<9; j++){
                // this for the rows:
                if(v[i][j]!='.' && (v[i][j]>'9' || v[i][j]<'1')){
                    return false;
                }
                if(v[i][j]!='.'){
                    if(dict_row.contains(v[i][j])){
                        if(dict_row[v[i][j]]){
                            return false;
                        }
                        
                    }
                    dict_row[v[i][j]]=true;
                }
                // this is for the column:
                if(v[j][i]!='.' && (v[j][i]>'9' || v[j][i]<'1')){
                    return false;
                }
                if(v[j][i]!='.'){
                    if(dict_column.contains(v[j][i])){
                        if(dict_column[v[j][i]]){
                            return false;
                        }
                        
                    }
                    dict_column[v[j][i]]=true;
                }

            }

            
        }

        

        for(int i = 0 ; i<9; i++){

            unordered_map<char,bool> dict_box;

            // testing for sub-box:
            for(int l = (i/3)*3 ; l<(i/3)*3+3; l++){
                for(int m = (i%3)*3 ; m<(i%3)*3+3; m++){
                    if(v[l][m]!='.'){
                        if(dict_box.contains(v[l][m])){
                            if(dict_box[v[l][m]])return false;
                        
                        }
                        dict_box[v[l][m]]=true;
                    }
                    

                }
            }
        }

        return true;

        


        
    }
};
