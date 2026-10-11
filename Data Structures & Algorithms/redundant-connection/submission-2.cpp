class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

       
        unordered_map<int,vector<int>> adj;

        for(int edge = 0 ; edge<edges.size(); edge++){
            int node1 = edges[edge][0];
            int node2 = edges[edge][1];
            if(existPath(adj, node1, node2,-1))return edges[edge];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
            

        }
  
    }

    bool existPath(unordered_map<int,vector<int>>& adj, int node1 , int node2,int prv_node){
        if(!adj.contains(node1) || !adj.contains(node2))return false;
        
        vector<int> neighbors = adj[node1];

        for(int neighbor : neighbors){
            if(neighbor==prv_node)continue;
            if(neighbor==node2 || existPath(adj,neighbor,node2,node1))return true;
        }

        return false;
    }
};
