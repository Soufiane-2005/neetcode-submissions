class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result={};

        vector<int> path={};

        backtracking(path, nums, result, 0);

        return result;
        
    }

    void backtracking(vector<int>& path, vector<int>& nums, vector<vector<int>>& result, int start){

        
        
        result.push_back(path);
        
        

        for(int i=start; i<nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(path, nums, result, i+1);
            path.pop_back();
        }
    }
};
