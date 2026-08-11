class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {


        
        unordered_map<int,int> dict1;

        for(int i : nums)dict1[i]++;

       
       vector<vector<int>> v(nums.size()+1);

       for(auto& [key,val]:dict1){
        v[val].push_back(key);
       }


        vector<int> result;

        for(int i = v.size()-1; i>=0; i--){
            if(k==0)break;
            if(v[i].size()>0){
                for(int j : v[i]){
                    result.push_back(j);
                    k--;
                }
            }
            
        }
       
       return result;

        
    }
};
