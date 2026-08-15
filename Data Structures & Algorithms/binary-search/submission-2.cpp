class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();


        int left = 0;
        int right = n-1;

        int middle = (right+left)/2;

        while(left<=right){ 
            if(target<nums[middle]){
                right=middle-1;
            }else if(target>nums[middle]){
                left=middle+1;
            }else{
                return middle;
            }
            middle = (right+left)/2;
        }

        return -1;

        
        
    }
};
