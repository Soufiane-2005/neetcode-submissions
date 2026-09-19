class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        vector<int> path;
        int sum=0;
        backtracking(path,nums, target, result, sum,0);
        return result;
    }

    void backtracking(vector<int>& path, vector<int>& nums, int target, vector<vector<int>>& result, int sum, int start){

        if(sum==target){
            result.push_back(path);
            return;
        }
        if(sum>target){
            return;
        }

        for(int i=start; i<nums.size(); i++){
            sum+=nums[i];
            path.push_back(nums[i]);
            backtracking(path, nums, target, result, sum,i);
            sum-=nums[i];
            path.pop_back();
        }
    }
};
