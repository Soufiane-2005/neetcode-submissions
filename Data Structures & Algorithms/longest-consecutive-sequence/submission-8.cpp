class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()<=1)return nums.size();
        int result = 1;

       // we are going to change nums to a set in this way i am gonna remove the duplicate numbers: 
       unordered_set<int> new_nums; 
       for(int num : nums){
        new_nums.insert(num);
       }

       // we are gonna create a simple graph without edges:
       unordered_map<int,vector<int>> graph;
       for(int i : new_nums){
            graph[i]={};
       }

       // i am going to fill that graph: so will have sub graphs
       for(auto& [key,val] : graph){
            if(graph.contains(key+1)){
                val.push_back(key+1);
            }
       }
        // here i am gonna find the result,
        // i will start with the parent and calculate the size of each sub graph.
        for(auto& [key,val] : graph){
            int count = 1;
            int k = key;
            if(!graph.contains(key-1)){
                while(val.size()!=0){
                    count++;
                    k++;
                    val=graph[k];
                }
            }

            if(result<=count){
                result=count;
            }
       }

       return result;


    



        
    }
        

       
};
