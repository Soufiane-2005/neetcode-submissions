class Solution {
public:
    bool isAnagram(string s, string t);
};


bool Solution::isAnagram(string s, string t){

    if(s.length()!=t.length())return false;

    int n = (int)s.length();

    unordered_map<char,int> firstString;
    unordered_map<char,int> secondString;

    for(int i = 0; i<n; i++){
        firstString[s[i]]++;
        secondString[t[i]]++;
    }

    for(auto& [key,val]: firstString){
        if(!secondString.contains(key)) return false;

        if(secondString[key]!=val) return false;

    }

    return true;



}