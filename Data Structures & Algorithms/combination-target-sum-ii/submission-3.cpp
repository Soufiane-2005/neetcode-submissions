class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> path;
        int sum = 0;
        int start = 0;
        sort(candidates.begin(),candidates.end());
        backtracking(path, candidates, result, target, start,sum);
        
        return result;

        
    }

    void backtracking(vector<int>& path, vector<int>& nums, vector<vector<int>>& result,int target, int start, int sum){

        if(sum==target){
            result.push_back(path);
            return;
        }
        if(sum>target)return;

        for(int i = start; i<nums.size(); i++){
            if(i>start && nums[i-1]==nums[i])continue;
            if(sum+nums[i]>target)break;
            sum+=nums[i];
            path.push_back(nums[i]);
            backtracking(path,nums,result,target,i+1,sum);
            sum-=nums[i];
            path.pop_back();
        }
    }
};
