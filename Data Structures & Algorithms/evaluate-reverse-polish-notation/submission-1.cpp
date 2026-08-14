class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        int n = tokens.size();

        stack<int> st;
        unordered_set<string> operators={"+","-","/","*"};


        for(int i = 0 ; i<n; i++){
            
            if(operators.contains(tokens[i])){
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();

                switch(tokens[i][0]){
                    case '+':
                        st.push(x+y);
                        break;
                    case '-':
                        st.push(x-y);
                        break;
                    case '*':
                        st.push(x*y);
                        break;
                    case '/':
                        st.push(x/y);
                        break;

                }


            }else{
                st.push(stoi(tokens[i]));
            }
            
        }

        return st.top();
        
    }
};
