class Solution {
public:
    vector<string> letterCombinations(string digits) {

        unordered_map<char, vector<char>> dict = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };

        string path;
        vector<string> result;
        if(digits.size()==0)return result;
        backtracking(path, digits, 0, result, dict);

        return result;
        
    }

    void backtracking(string& path, string& digits,int curr_dig_ind, vector<string>& result, unordered_map<char,vector<char>>& dict){

        if(path.size()==digits.size()){
            result.push_back(path);
            curr_dig_ind = 0;
            return;
        }

        char curr_dig = digits[curr_dig_ind];

        vector<char> characters = dict[curr_dig];
        for(int i = 0; i<=characters.size()-1; i++){
            path.push_back(characters[i]);
            backtracking(path, digits, curr_dig_ind+1, result, dict);
            path.pop_back();

        }
    }
};
