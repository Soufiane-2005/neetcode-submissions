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

        double max_time = pq.top().second;

        pq.pop();

        int count = 1;

        while(!pq.empty()){
            double x = pq.top().second;

            if(x>max_time){
                max_time = x;
                count++;
            }

            pq.pop();

        }
        

        return count;

        


        

        


        
        
    }
};
