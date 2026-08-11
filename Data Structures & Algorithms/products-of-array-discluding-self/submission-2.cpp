class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {


        // here i will not use division approach :

        vector<int> result(nums.size(),1);

        // left array: 
        vector<int> left(nums.size(),1);

        for(int i = 1 ; i<nums.size(); i++){
            left[i]=left[i-1]*nums[i-1];
        }


        // right array: 
        vector<int> right(nums.size(),1);

        for(int i = nums.size()-2; i>=0; i--){
            right[i]=right[i+1]*nums[i+1];
        }


        for(int i=0 ; i<nums.size(); i++){

            result[i]=left[i]*right[i];
        } 

        return result;






// here i use division approach: 


        // vector<int> result(nums.size(),0);

        // int p = 1;

        // bool zero_exist=false;
        // int zeros=0;

        // for(int num : nums){
        //     if(num!=0){
        //         p*=num;
        //     }else{
        //         zero_exist=true;
        //         zeros++;
        //     }
            
        // }

        // for(int i = 0 ; i<nums.size(); i++){
            
        //     if(zero_exist){
        //         if(zeros==1){
        //             if(nums[i]==0){
        //                 result[i]=p;
        //             }else{
        //                 result[i]=0;
        //             }
        //         }else{
        //             result[i]=0;
        //         }

        //     }else{
        //         result[i]=p/nums[i];
        //     }
            
            
            
        // }

        // return result;



    }
};
