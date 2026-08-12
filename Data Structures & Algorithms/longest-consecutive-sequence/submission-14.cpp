class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()<=1)return nums.size();
        int result = 1;

       // we are going to change nums to a set in this way i am gonna remove the duplicate numbers: 
       unordered_set<int> new_nums; 
       for(int num : nums){
        new_nums.insert(num);
       }

       for(int num : new_nums){
        int count=1;
        int current_num=num;
        if(!new_nums.contains(current_num-1)){
            while(new_nums.contains(current_num+1)){
                count++;
                current_num++;
            }

        }

        if(count>result){
            result=count;
        }
       }




       return result;


    



        
    }
        

       
};
