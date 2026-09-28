struct node {
    node* children[26];
    bool endword;
};


class WordDictionary {
    node* root;
public:
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* current = root;

        for(char ch : word){
            int ind = ch - 'a';
            node* child = current->children[ind];

            if(!child){
                current->children[ind] = new node();
                child = current->children[ind];
            }
            current = child;
        }

        current->endword = true;
    }
    
    bool search(string word) {
        node* current = root;
        return search(word,0,current);
    }


    bool search(string word, int i, node* current){

        if(i==(int)word.size())return current->endword;

        if(word[i]=='.'){
            for(int ind = 0 ; ind<26; ind++){
                if(!current->children[ind])continue;
                bool found = search(word, i+1, current->children[ind]);
                if(found)return true;
            }

        }else{
            int ind = word[i] - 'a';
            if(!current->children[ind])return false;
            bool found = search(word, i+1, current->children[ind]);
            if(found)return true;
        }

        return false;

    }
};
