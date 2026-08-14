class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n2 = s2.size();
        int n1 = s1.size();


        
        unordered_map<char,int> dict;
        for(char ch : s1){
            dict[ch]++;
        }

        int left = -1;
        int right=0;

        unordered_map<char,int> currentWindow;


        while(right<n2){

            currentWindow[s2[right]]++;

            if(!dict.contains(s2[right])){
                while(left<right){
                    left++;
                    currentWindow.erase(s2[left]);
                }
            }else{
                while(currentWindow[s2[right]]>dict[s2[right]]){
                    left++;
                    currentWindow[s2[left]]--;
                }
            } 
            if((right-left)==n1)return true;

            right++;
        }

        







        return false;
        
    }
};
