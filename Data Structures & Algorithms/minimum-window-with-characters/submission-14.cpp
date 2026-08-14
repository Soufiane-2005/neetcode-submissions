class Solution {
public:
    string minWindow(string s, string t) {

        int slen = s.length();
        int tlen = t.length();

        unordered_map<char,int> t_dict;

        if(tlen > slen || tlen == 0 || slen == 0) {
            return "";
        }

        for(char ch : t){
            t_dict[ch]++;
        }

        pair<int,int> index_of_substring = {-1, -1};

        int left = 0;
        int right = 0;

        int len_of_substring = 0;

        int have = 0;
        int need = t_dict.size();

        unordered_map<char,int> currentWindow;

        while(right < slen){

            currentWindow[s[right]]++;

            if(t_dict.contains(s[right]) &&
               t_dict[s[right]] == currentWindow[s[right]]) {
                have++;
            }

            while(have == need){

                if(len_of_substring == 0 ||
                   (right - left + 1) < len_of_substring) {

                    index_of_substring.first = left;
                    index_of_substring.second = right;
                    len_of_substring = right - left + 1;
                }

                char ch = s[left];

                if(t_dict.contains(ch)) {
                    currentWindow[ch]--;

                    if(currentWindow[ch] < t_dict[ch]) {
                        have--;
                    }
                }

                left++;
            }

            right++;
        }

        if(index_of_substring.first == -1) {
            return "";
        }

        string result = "";

        for(int i = index_of_substring.first;
            i <= index_of_substring.second;
            i++) {
            result += s[i];
        }

        return result;
    }
};