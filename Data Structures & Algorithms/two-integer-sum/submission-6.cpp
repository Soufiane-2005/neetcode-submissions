class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        if(nums.size()==2) return {0,1};

        unordered_map<int,int> dict;

        for(int i=0;i<nums.size();i++){
            int next = target-nums[i];
            if(dict.contains(next)){
                return {dict[next],i};
            }
            dict[nums[i]]=i;
        }

       


        
        

      
        
    }

    
};
