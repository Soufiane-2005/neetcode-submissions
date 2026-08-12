class Solution {
public:

    int trap(vector<int>& height) {

        int water_area=0;

        int n = height.size();

        

        // water_area[i] = min(left[i],right[i])-height[i]
        // water_area = sum{1,n-2}(water_area[i]);


        unordered_map<int,int> left,right;


        //for the left:
        left[1]=height[0];
        for(int i = 2; i<n-1; i++){
            left[i]=max(height[i-1],left[i-1]);
            
        }

        //for the right:
        right[n-2]=height[n-1];
        for(int i = n-3 ; i>0; i--){
            right[i]=max(height[i+1],right[i+1]);
            
        }

        for(int i = 1; i<n-1; i++){
            int s=min(left[i],right[i])-height[i];
            if(s>=0){
                water_area+=s;
            }
            
        }





        
        return water_area;

        
    }
};
