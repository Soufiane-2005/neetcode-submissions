class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        //building the adjacency list : 
        vector<vector<int>> adj(n,vector<int>{});
        for(int i = 0 ; i<edges.size(); i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        //finding a cycle in that graph : 
        
        vector<int> state(n,0);
        for(int node = 0 ; node<n; node++){
            if(state[node]==2)continue;
            if(dfs(adj,node,-1,state))return false;
            if(node==0){
                for(int st : state){
                    if(st==0)return false;
                }
            }
        }

        return true;

    }

    bool dfs(vector<vector<int>>& adj, int node, int prv_node, vector<int>& state){
        state[node]=1;
        for(int neighbor : adj[node]){
            if(neighbor==prv_node)continue;
            if(state[neighbor]==1)return true;
            if(state[neighbor]==2)continue;
            if(dfs(adj,neighbor,node,state))return true;
        }

        state[node]=2;

        return false;
    }
};
