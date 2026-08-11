class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size()==0)return "";

        int key = strs.size()+1;

        string result;

        for(string str:strs){
            for(int ch_num : str){
                char ch = ch_num+key;
                result+=ch;
            }
            result+=' ';
        }


        return result;



    }

    vector<string> decode(string s) {
        if(s.size()==0)return {};

        vector<string> result;
        char space = ' ';



        int key=1;

        for(char ch: s){
            if(ch==space) key++;
        }

        string word;


        for(char ch : s){

            if(ch==space){
                result.push_back(word);
                word = "";
            }else{
                char temp = ch-key;
                word+=temp;

            }



        }

        return result;




    }
};
