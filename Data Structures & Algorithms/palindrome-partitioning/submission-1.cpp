class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;

        vector<string> temp;

       

        palindrome(s,0,temp,result);

        return result; 

        
        


        
    }

    void palindrome(string& s, int start, vector<string>& temp, vector<vector<string>>& result){


        if(start==s.size()){
            result.push_back(temp);
            return;
        }

        for(int i = start; i<s.size(); i++){

            if(is_palindrome(s,start,i)){

                string path = s.substr(start,i-start+1);

                temp.push_back(path);

                palindrome(s,i+1,temp,result);

                temp.pop_back();


            }
        }


        
       
    }



    bool is_palindrome(string s,int i, int j){
        if(i>=j)return true;
        return s[i]==s[j] && is_palindrome(s,i+1,j-1);  
    }
};
