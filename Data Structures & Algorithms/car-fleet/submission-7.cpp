class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

       


        priority_queue<pair<int,int>> pq;

        for(int k = 0 ; k<n; k++){
            pq.push({position[k],k});
        }

        vector<double> time(n,0);

        for(int k=n-1;k>=0; k--){
            pair<int,int> p = pq.top();
            time[k] = (double)(target-p.first)/(double)(speed[p.second]);
            pq.pop();
        }






        stack<double> st;

        for(int k = n-1; k>=0; k--){
            cout<<time[k]<<endl;
            if(st.empty()){
                st.push(time[k]);
            }else{
                double x = st.top();
                if(time[k]>x){
                    st.push(time[k]);
                }
            }


        }
        

        return st.size();

        


        

        


        
        
    }
};
