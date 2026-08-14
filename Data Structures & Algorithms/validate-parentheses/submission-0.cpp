class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        

        unordered_map<char,char> dict={
        {')','('},
        {']','['},
        {'}','{'}
        };

        for(char ch:s){
            if(dict.contains(ch)){
                if(st.empty())return false;
                if(dict[ch]!=st.top())return false;
                st.pop();
            }else{
                st.push(ch);
            }
            
        }
      
        return st.empty();
        
    }
};
