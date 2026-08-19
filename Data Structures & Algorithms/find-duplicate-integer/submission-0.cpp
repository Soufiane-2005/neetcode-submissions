class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_set<int> s;

        int i = 0;
        while(true){
            if(s.contains(nums[i])){
                return nums[i];
            }
            s.insert(nums[i]);
            i++;
        }

        
    }
};
