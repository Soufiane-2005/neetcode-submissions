class Solution {
public:
    int singleNumber(vector<int>& nums) {


        unordered_map<int,int> dict;

        for(int num : nums){
            dict[num]++;
        }
        
        for(auto& [key,val] : dict){
            if(val==1){
                return key;
            }
        }
        
    }
};
