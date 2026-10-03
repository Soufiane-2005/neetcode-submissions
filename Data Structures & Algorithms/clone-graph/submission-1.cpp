/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
public:

    Node* cloneGraph(Node* node){
       
        Node* head = node;
       
       unordered_map<Node*,Node*> dict;

       dfs(node,dict);

       return dict[head];

    }

    void dfs(Node* node, unordered_map<Node*,Node*>& dict){

        if(!node)return;
        
        if(dict.contains(node))return;
        dict[node]=new Node(node->val);
        
        for(Node* neighbor : node->neighbors){
            dfs(neighbor,dict);
            dict[node]->neighbors.push_back(dict[neighbor]);
            
        }
        



    }


    
};
