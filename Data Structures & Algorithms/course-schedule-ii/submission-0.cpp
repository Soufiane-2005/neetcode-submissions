class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses,vector<int>{});


        for(int i = 0 ; i<prerequisites.size(); i++){
            int node = prerequisites[i][0];
            int neighbor = prerequisites[i][1];
            adj[node].push_back(neighbor);
        }

        vector<int> result;

        vector<int> state(numCourses,0);
        for(int node = 0 ; node<numCourses; node++){
            if(state[node]!=2){
                dfs(adj,node,state,result);
            }
        }

        for(int node : result){
            if(node==-1)return {};
        }

        return result;

        
    }

    void dfs(vector<vector<int>>& adj, int node, vector<int>& state, vector<int>& result){

        state[node]=1;

        for(int neighbor : adj[node]){
            if(state[neighbor]==1){
                result.push_back(-1);
                return;
            }
            if(state[neighbor]==2)continue;
            dfs(adj,neighbor,state,result);
        }

        state[node]=2;
        result.push_back(node);
    }
};
