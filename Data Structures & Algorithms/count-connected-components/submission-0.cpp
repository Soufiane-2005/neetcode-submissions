class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        //creating an adjacency list:
        vector<vector<int>> adj(n,vector<int>{});
        for(int i = 0 ; i<edges.size(); i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        //detect how many connected components are in this graph:

        int result = 0 ; 
        vector<bool> visited(n,false);
        for(int node = 0 ; node<n; node++){
            if(!visited[node]){
                result++;
                dfs(adj,node,visited);
            }
            
        }

        return result;


    }

    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited){
        visited[node]=true;

        for(int neighbor : adj[node]){
            if(visited[neighbor])continue;
            dfs(adj,neighbor,visited);
        }
    }
};
