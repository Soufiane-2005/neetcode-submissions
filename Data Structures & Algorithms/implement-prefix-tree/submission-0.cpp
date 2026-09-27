
struct node {
    char character;
    node* children[26];
    bool endword;
};

class PrefixTree {
    node* root;
public:
    PrefixTree() {
        root = new node();
    }
    
    void insert(string word) {
        node* current = root;

        for(char ch : word){

            int ind = ch - 'a';

            node* child = current->children[ind];

            if(!child){
                current->children[ind] = new node();
                child = current->children[ind];
                child->character = ch;
            }
            current = child; 

        }

        current->endword = true;
    }
    
    bool search(string word) {

        node* current = root;
        
        for(char ch : word){

            int ind = ch - 'a';
            node* child = current->children[ind];

            if(!child)return false;

            current = child;
        }

        return current->endword;
        
    }
    
    bool startsWith(string prefix) {
        node* current = root;
        
        for(char ch : prefix){

            int ind = ch - 'a';
            node* child = current->children[ind];

            if(!child)return false;

            current = child;
        }

        return true;
    }
};
