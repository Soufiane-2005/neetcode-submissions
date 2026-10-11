class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        //construction an adjacency list : 
        vector<vector<int>> adj(numCourses,vector<int>{});
        for(int i = 0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // 0 -> not yet visited, 1 -> currently visited , 2 -> finished
        vector<int> state(numCourses,0);

        for(int i = 0 ; i<numCourses ; i++){
           if(dfs(adj,i,state))return false;
        }

        return true;
        
        
    }

    bool dfs(vector<vector<int>>& adj, int node ,vector<int>& state){
        state[node]=1;

        for(int neighbor : adj[node]){
            if(state[neighbor]==1)return true;
            if(state[neighbor]==2)continue;
            if(dfs(adj,neighbor,state))return true;

        }
        state[node]=2;
        return false;

    }

    
};
