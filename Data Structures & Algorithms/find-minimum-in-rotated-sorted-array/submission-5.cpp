class Solution {
public:
    int findMin(vector<int> &nums) {

        int n = nums.size();
        
        

        int left=0;
        int right= n-1;

        int middle = (left+right)/2;


        if(nums[left]<=nums[right]){
            return nums[left];
            
        }else{
            while(left<=right){
                if(nums[middle]<nums[right]){
                    right=middle;
                }else if(nums[middle]>nums[right]){
                    left = middle+1;
                }else{
                    return nums[middle];
                }

                middle = (left+right)/2;

            }
        }

        
    }
};
