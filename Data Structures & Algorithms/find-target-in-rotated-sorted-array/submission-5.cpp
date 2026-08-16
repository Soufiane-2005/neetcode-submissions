class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();


        int left =0;
        int right = n-1;
        int middle;

        while(left<=right){
            middle = (left+right)/2;
            
            if(nums[middle]==target)return middle;

           

            if(nums[middle]<=nums[right]){

                if(target>nums[middle] && target<=nums[right]){
                    left = middle + 1;
                }else{
                    right = middle - 1; 
                }
            }

            

            if(nums[left]<=nums[middle]){

                if(target>=nums[left] && target<nums[middle]){
                    right = middle -1;
                }else{
                    left = middle + 1;
                }


            }
        }

        return -1;

       
    }
};
