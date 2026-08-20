class Node {
    public: 
        int key;
        int val;
        Node* prv;
        Node* next;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            this->prv = nullptr;
            this->next = nullptr;
        }
};

class LRUCache {
    int capacity;
    unordered_map<int,Node*> dict;
    Node head{0,0};
    Node tail{0,0};
    Node* h = &head; 
    Node* t = &tail;  
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->h->next = t;
        this->t->prv = h;
    }
    
    int get(int key) {
        
        if(dict.contains(key)){

            
            dict[key]->prv->next = dict[key]->next;
            dict[key]->next->prv = dict[key]->prv;

            
            dict[key]->next = t;
            dict[key]->prv = t->prv;
            t->prv->next = dict[key];
            t->prv = dict[key];

            return dict[key]->val;
        }

        return -1;
        

        
    }
    
    void put(int key, int value) {

      if(dict.contains(key)){

        dict[key]->prv->next = dict[key]->next;
        dict[key]->next->prv = dict[key]->prv;

        dict[key]->val = value;

        dict[key]->next = t;
        dict[key]->prv = t->prv;

        t->prv->next = dict[key];
        t->prv = dict[key];

      }else{

        Node* node = new Node(key, value);

        if(dict.size()==capacity){
            int k = h->next->key;
            h->next = h->next->next;
            h->next->prv = h;
            dict.erase(k);

        }
        node->next = t;
        node->prv = t->prv;
        t->prv->next = node;
        t->prv = node;
        dict[key] = node;

        
      }
      

    }
};
