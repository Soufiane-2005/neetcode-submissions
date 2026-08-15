class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        vector<double> time(n,0);


        vector<int> indices(n,0);

        unordered_map<int,int> dict;
        priority_queue<int> pq;

        for(int k = 0 ; k<n; k++){
            time[k]=((double)(target-position[k]))/(double)speed[k];
            dict[position[k]]=k;
            pq.push(position[k]);
        }

        

        

        for(int k = n-1 ; k>=0 ;k--){
            int index = dict[pq.top()];
            pq.pop();
            indices[k]=index;
        }

        vector<double> new_time(n,0);
        vector<int> new_position(n,0);

        for(int k = 0;  k<n; k++){
           
            new_time[k]=time[indices[k]];
            new_position[k]=position[indices[k]];
        }




        stack<double> st;

        for(int k = n-1; k>=0; k--){
            cout<<new_time[k]<<endl;
            if(st.empty()){
                st.push(new_time[k]);
            }else{
                double x = st.top();
                if(new_time[k]>x){
                    st.push(new_time[k]);
                }
            }


        }
        

        return st.size();

        


        

        


        
        
    }
};
