class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> path;
        int n = nums.size();
        unordered_set<int> chosen;
        backtracking(path,nums,chosen,n,result);
        return result;
        
    }

    void backtracking(vector<int>& path, vector<int>& nums,unordered_set<int>& chosen, int n, vector<vector<int>>& result){

        if(path.size()==n){
            result.push_back(path);
            return;
        }

        for(int i=0 ; i<n ; i++){
            if(chosen.contains(i))continue;
            path.push_back(nums[i]);
            chosen.insert(i);
            backtracking(path,nums,chosen,n,result);
            chosen.erase(i);
            path.pop_back();
        }
    }
};
