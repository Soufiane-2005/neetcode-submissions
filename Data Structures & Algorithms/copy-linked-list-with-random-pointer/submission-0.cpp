/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        
        Node dummy(0);
        Node* curr1 = &dummy;
        

        Node* h = head;

        unordered_map<Node*,Node*> dict;

        while(head){

            Node* node = new Node(head->val);

            dict[head] = node;

            curr1->next = node;

            curr1 = node;
            
            head = head->next;   

        }
        Node* curr2 = dummy.next;

        while(h){

            if(h->random){
                curr2->random = dict[h->random];
            }

            h=h->next;
            curr2=curr2->next;


        }



        return dummy.next;
        
    }
};
