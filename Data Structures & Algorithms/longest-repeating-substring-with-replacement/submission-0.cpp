class Solution {
public:
    int characterReplacement(string s, int k) {

        int result = 0;

        int n = s.size();


        int left = 0;
        int right = 0;
        int maxFrequent_character=0;

        unordered_map<char,int> dict;

        while(right<n){

            dict[s[right]]++;

            maxFrequent_character=max(maxFrequent_character, dict[s[right]]);

           

            while(((right-left+1)-maxFrequent_character)>k){
                dict[s[left]]--;
                left++;
            }

            result=max(result, right-left+1);

            right++;
        }

        return result;
        
    }
};
