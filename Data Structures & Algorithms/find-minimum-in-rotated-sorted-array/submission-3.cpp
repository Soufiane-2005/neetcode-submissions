class Solution {
public:
    int findMin(vector<int> &nums) {

        int n = nums.size();
        int min_num = INT_MAX;
        

        int left=0;
        int right= n-1;

        int middle = (left+right)/2;


        if(nums[left]<=nums[right]){
            return nums[left];
            
        }else{
            while(left<=right){
                if(nums[middle]<nums[right]){
                    if(nums[middle-1]<nums[middle]){
                        right=middle-1;
                    }else{
                        return nums[middle];
                    }
                }else if(nums[middle]>nums[right]){
                    left = middle+1;
                }else{
                    return nums[middle];
                }

                middle = (left+right)/2;

            }
        }








        return min_num;
        
    }
};
