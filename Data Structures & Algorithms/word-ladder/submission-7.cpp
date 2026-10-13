class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 1;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        wordList.push_back(beginWord);

        unordered_map<string,bool> words_visited;
        for (string s : wordList) {
            words_visited[s]=false;
        }

        queue<pair<string, int>> q;
        words_visited[beginWord]=true;
        q.push({beginWord, 1});
        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            string s = p.first;
            int number = p.second;
            for (int i = 0; i < s.size(); i++) {
                char origin = s[i];
                int k = 0;
                while (k != 26) {
                    char ch = 'a' + k;
                    s[i] = ch;
                    if (words_visited.contains(s)) {
                        if (s == endWord) return number + 1;
                        if (!words_visited[s]) {
                            words_visited[s]=true;
                            q.push({s, number + 1});
                        }
                    }

                    s[i] = origin;
                    k++;
                }
            }
        }

        return 0;
    }
};
