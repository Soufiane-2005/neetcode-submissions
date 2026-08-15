class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        stack<pair<int,int>> st;

        int max_area=0;

        for(int i = 0; i<n; i++){

            pair<int,int> current_bar = {i,heights[i]};
            int current_height = current_bar.second;


            if(!st.empty()){
                while(!st.empty() && st.top().second>current_height){
                    pair<int,int> previous_bar = st.top();
                    int previous_height = previous_bar.second;
                    int area = (i-previous_bar.first)*previous_height;
                    max_area=max(max_area,area);
                    current_bar.first=previous_bar.first;
                    st.pop();
                }
            }
            st.push(current_bar);
           

        }

        while(!st.empty()){
            pair<int,int> last_bar = st.top();
            int last_bar_started_index = last_bar.first;
            int last_bar_height = last_bar.second;
            int area = (n-last_bar_started_index)*last_bar_height;

            max_area = max(area,max_area);
            st.pop();
        }

        return max_area;


        











        
    }
};
