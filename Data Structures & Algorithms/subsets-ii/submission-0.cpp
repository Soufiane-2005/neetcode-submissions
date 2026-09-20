class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> path;
        vector<vector<int>> result;
        int start = 0;
        sort(nums.begin(), nums.end());
        backtracking(path,nums,start,result);
        return result;
        
    }

    void backtracking(vector<int>& path,vector<int>& nums,int start, vector<vector<int>>& result){

        result.push_back(path);


        for(int i = start; i<nums.size(); i++){
            if(i>start && nums[i]==nums[i-1])continue;
            path.push_back(nums[i]);
            backtracking(path,nums,i+1,result);
            path.pop_back();
        }
    }
};
