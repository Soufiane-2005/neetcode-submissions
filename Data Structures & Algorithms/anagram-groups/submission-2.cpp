class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;

       

        // this map where i am gonna put for every binary_number an array that contains strs

        // i am using map because c++ doesn't know how to hash a vector (when i use unordered_map)
        map<vector<int>,vector<string>> dict;

        // now i am gonna look at every string and try to hash it by associating it to a binary number for example "acd"=[1,0,1,1,0,0.....] and cda=[1,0,1,1,0,0....] so they are the same so to put it simply we are going to create a dict ={  [1,0,1,1,0,0,0....] : ["acd","cda"]                } this is the idea.

        for(string str : strs){

             //let's call this one : binary number with 26 bits
        vector<int> binary_number(26,0); // so first i am gonna set them to 0;


            for(int ch : str){
                binary_number[ch-'a']+=1;
            }

            if(!dict.contains(binary_number)){
                dict[binary_number]={str};
            }else{
                dict[binary_number].push_back(str);
            }

            
            

            
        }

        for(auto& [key,val] : dict){
            result.push_back(val);
        }

        return result;

        


        
    }

    
};
