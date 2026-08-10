class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> count;

        for(int j : nums){
            count[j]++;
        }

        for(auto& [key, val] : count) if(val!=1) return true;

        return false; 




        
    }
};