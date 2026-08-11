class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> result(nums.size(),0);

        int p = 1;

        bool zero_exist=false;
        int zeros=0;

        for(int num : nums){
            if(num!=0){
                p*=num;
            }else{
                zero_exist=true;
                zeros++;
            }
            
        }

        for(int i = 0 ; i<nums.size(); i++){
            
            if(zero_exist){
                if(zeros==1){
                    if(nums[i]==0){
                        result[i]=p;
                    }else{
                        result[i]=0;
                    }
                }else{
                    result[i]=0;
                }

            }else{
                result[i]=p/nums[i];
            }
            
            
            
        }

        return result;



    }
};
