class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;

       

        
        // i am using map because c++ doesn't know how to hash a vector (when i use unordered_map)
        map<vector<int>,vector<string>> dict;

        // now i am gonna look at every string and try to hash it by associating it to a hash_vector for example "acd"=[1,0,1,1,0,0.....] and cda=[1,0,1,1,0,0....] so they are the same so to put it simply we are going to create a dict ={  [1,0,1,1,0,0,0....] : ["acd","cda"]                } this is the idea. and for aab = [2,1,0,0,...] and bba=[1,2,0,0,0...]

        for(string str : strs){

             //let's call this one : hash_vector with 26 number(from 1 to 26)
        vector<int> hash_vector(26,0); // so first i am gonna set all of them to 0;


            for(int ch : str){
                hash_vector[ch-'a']+=1;
            }

            if(!dict.contains(hash_vector)){
                dict[hash_vector]={str};
            }else{
                dict[hash_vector].push_back(str);
            }

            
            

            
        }

        for(auto& [key,val] : dict){
            result.push_back(val);
        }

        return result;

        


        
    }

    
};
