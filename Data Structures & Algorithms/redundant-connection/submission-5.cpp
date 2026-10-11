class Solution {
   public:
    void unite(int node2, int node1, vector<int>& parent) { parent[node2] = node1; }

    int find(int node1, vector<int>& parent) {
        if (parent[node1] == node1) {
            return node1;
        }
        return find(parent[node1], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent;
        for (int i = 0; i <= edges.size(); i++) parent.push_back(i);

        vector<int> rank(edges.size() + 1, 1);
        for (vector<int> edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            int root1 = find(node1, parent);
            int root2 = find(node2, parent);

            if (root1 == root2) {
                return edge;
            }

            if (rank[root1] > rank[root2]) {
                unite(root2, root1, parent);
            } else if (rank[root1] < rank[root2]) {
                unite(root1, root2, parent);
            } else {
                unite(root2, root1, parent);
                rank[root1]++;
            }
        }

        return {};
    }
};
