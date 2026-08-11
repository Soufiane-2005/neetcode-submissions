class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> dict1;

        for(int i : nums)dict1[i]++;

       map<int, vector<int>> dict2;

       for(auto& [key,val] : dict1){
        dict2[val].push_back(key);
       }

       vector<vector<int>> v(nums.size());

       for(auto& [key,val] : dict2){
        v[key-1]=val;
       }

        vector<int> result;
       for(int j=nums.size()-1; j>=0; j--){
        if(k==0)break;
            if(v[j].size()!=0){
                for(int m : v[j]){
                    result.push_back(m);
                    k--;
                }
            }
       }

       return result;

        
    }
};
