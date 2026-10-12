class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(beginWord==endWord)return 1;
        if(find(wordList.begin(), wordList.end(), endWord)==wordList.end())return 0;
        wordList.push_back(beginWord);
        // i need to create a adj list : 
        unordered_map<string,vector<string>> adj;
        for(int i = 0 ; i<wordList.size()-1; i++){
            string node1 = wordList[i];
            for(int j = i+1; j<wordList.size(); j++){
                string node2 = wordList[j];
                if(oneDifferent(node1,node2,0,0)){
                    adj[node1].push_back(node2);
                    adj[node2].push_back(node1);
               }
            }

        
        }

    
        // now i need to do the bfs and find all the paths from begin word to the endword
        int result = bfs(adj, beginWord, endWord);
        if(result==INT_MAX)return 0;
        return result;

        
        
        
    }
    bool oneDifferent(string& s1, string& s2, int i, int count){
        if(i>=s1.size() && count==1)return true;
        if(i>=s1.size() || s1[i]!=s2[i] && count>=1)return false;
        if(s1[i]!=s2[i])count++;
        return oneDifferent(s1,s2,i+1,count);
    }

    int bfs(unordered_map<string,vector<string>>& adj, string& beginWord, string& endWord){

        int result = INT_MAX;

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        // because we are in a directed graph we need to make sure that we don't do an infinit visit a - b : b is neighbor of a and a is neighbor of b;
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();
            string& s1 = p.first;
            int number = p.second;
            for(string s2 : adj[s1]){
                if(s2==endWord){
                    return number+1;
                }
                if(visited.contains(s2))continue;
                visited.insert(s2);
                q.push({s2,number+1});
            }

        }
        
        return result;
        
    }
};
