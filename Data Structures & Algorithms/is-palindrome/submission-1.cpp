class Solution {
public:
    bool isPalindrome(string s) {

        if(s.size()<=1)return true;
        
        vector<char> v;

        //we are gonna delete characters that are not in (A-Z, a-z) and numbers (0-9).

        for(char ch : s){
            if((ch>='A'&& ch<='Z') || (ch<='z' && ch>='a') || (ch>='0' && ch<='9')){
                v.push_back(tolower(ch));
            }
        }


        // we are gonna create two pointers now: 
        int i =0;
        int j = v.size()-1;

        while((i<=j)){
            if(v[i]!=v[j])return false;
            i++;
            j--;
        }
        return true;

    }
};
