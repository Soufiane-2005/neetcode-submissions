class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {




        int n = position.size();

       


        priority_queue<pair<int,double>> pq;

        for(int k = 0 ; k<n; k++){

            double time = (double)(target-position[k])/(double)(speed[k]);

            pair<int,double> position_time = {position[k],time};

            pq.push(position_time);
        }

        





        stack<double> st;

        for(int k = n-1; k>=0; k--){
            
            if(st.empty()){
                st.push(pq.top().second);
            }else{
                double x = st.top();
                if(pq.top().second>x){
                    st.push(pq.top().second);
                }
            }

            pq.pop();


        }
        

        return st.size();

        


        

        


        
        
    }
};
