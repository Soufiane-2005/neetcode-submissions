class Solution {
public:
    int maxArea(vector<int>& heights) {

        int amount_water=0;

        int i = 0;
        int j = heights.size()-1;

        while(i<heights.size() && j >=0 && i<j){

            int temp = (j-i)*min(heights[i],heights[j]);

            amount_water= max(temp,amount_water);

            if(heights[i] < heights[j]){
                i++;
            }else if(heights[i]>=heights[j]){
                j--;
            }
        }

        return amount_water;
        
    }
};
