class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(beginWord==endWord)return 1;
        if(find(wordList.begin(), wordList.end(), endWord)==wordList.end())return 0;
        wordList.push_back(beginWord);
        // i need to create a adj list : 
        unordered_map<string,vector<string>> adj;
        unordered_set<string> words;
        for(string s : wordList){
            words.insert(s);
        }

        for(string s : wordList){
            string temp = s;
            for(int i=0 ; i<s.size(); i++){
                char orig = s[i];
                int k = 0;
                while(k!=26){
                    char ch = 'a'+ k;
                    if(ch!=orig){
                        s[i] = ch;
                        if(words.contains(s)){
                            adj[temp].push_back(s);
                        }
                    }
                    k++;

                }
                s[i]=orig;
            }

            int result = bfs(adj, beginWord, endWord);
            if(result!=INT_MAX)return result;
        }

    
        // now i need to do the bfs and find all the paths from begin word to the endword
        int result = bfs(adj, beginWord, endWord);
        if(result==INT_MAX)return 0;
        return result;

        
        
        
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
