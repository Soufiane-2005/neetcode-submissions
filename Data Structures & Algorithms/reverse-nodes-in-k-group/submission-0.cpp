/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* start = head;

        ListNode dummy{};
        ListNode* curr = &dummy;
        int i = 0;

        ListNode* nextGroup;

        while(head){

            i++;

            if(i==k){
                nextGroup = head->next;
                curr->next = reverse1Group(start,k);
                curr = start;
                head = start;
                start->next = nextGroup;
                start = nextGroup;
                
                i=0;

            }

            
            head = head->next;
        }

        if(i){
            curr->next = start;
        }

        return dummy.next;

        
    }

    ListNode* reverse1Group(ListNode* head, int k){

        ListNode* prv = nullptr;
        ListNode* curr = head;
        ListNode* next_node = head;

        while(k){

            next_node = curr->next;
            curr->next = prv;
            prv = curr;
            curr = next_node;
            k--;

        }


        return prv;


    }


};
