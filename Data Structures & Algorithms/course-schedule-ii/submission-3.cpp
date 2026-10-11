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
                if(dfsIsCycle(adj,node,state,result))return {};
            }
        }


        return result;

        
    }

    bool dfsIsCycle(vector<vector<int>>& adj, int node, vector<int>& state, vector<int>& result){

        state[node]=1;

        for(int neighbor : adj[node]){
            if(state[neighbor]==1)return true;
            if(state[neighbor]==2)continue;
            if(dfsIsCycle(adj,neighbor,state,result))return true;
        }

        state[node]=2;
        result.push_back(node);
        return false;

    }
};
