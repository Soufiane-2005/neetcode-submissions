class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()<=1)return nums.size();

        map<int,vector<int>> dict;


        // this one is o(n);
        for(int i : nums){
            if(!dict.contains(i)){
                dict[i]={};
            }
        }

        unordered_set<int> seen;


        int g = 1;


        // this is o(n)

        for(auto& [key,val] : dict){

            if(dict.contains(key+1)){
                val.push_back(key+1);
            }

        }
        
        for(auto& [key,val] : dict){

            seen.insert(key);
            
            int count=1;

            int k = key;
            while(dict.contains(k+1) && !seen.contains(k+1)){
                count++;
                seen.insert(k+1);
                k++;
                
            }

            if(g<=count){
                g=count;
            }
        }

        return g;
    }
        

       
};
