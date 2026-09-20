class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string path;
        int open=0,close=0;
        backtracking(path,n,result,open,close);
        
        return result;
    }

    void backtracking(string& path, int n, vector<string>& result,int open,int close){

        if(path.size()==2*n){
            result.push_back(path);
            return;
        }

        for(char ch : {'(',')'}){
            if(open==close && ch==')')continue;
            if(open==n && ch=='(')continue;
            if(ch=='(')open++;
            if(ch==')')close++;
            path.push_back(ch);
            backtracking(path,n,result,open,close);
            if(ch=='(')open--;
            if(ch==')')close--;
            path.pop_back();
        }

        
        
    }
};
