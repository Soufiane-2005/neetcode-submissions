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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* current1 = list1;
        ListNode* current2 = list2;

        ListNode* head = nullptr;

        ListNode* previous_node;

        while(current1!=nullptr && current2!=nullptr){

            if(current1->val<=current2->val){
                if(head==nullptr){
                    head = new ListNode(current1->val);
                    previous_node = head;
                }else{
                    ListNode* node = new ListNode(current1->val);
                    previous_node->next = node;
                    previous_node=node;
                }
                current1 = current1->next;
            }else{
                if(head==nullptr){
                    head = new ListNode(current2->val);
                    previous_node = head;
                }else{
                    ListNode* node = new ListNode(current2->val);
                    previous_node->next = node;
                    previous_node = node;
                }
                current2 = current2->next;
            }

        }

        while(current1!=nullptr){

            if(head==nullptr){
                head = new ListNode(current1->val);
                previous_node = head;
            }else{
                ListNode* node = new ListNode(current1->val);
                previous_node->next = node;
                previous_node = node;
                
            }

            current1 = current1->next;
        }

        while(current2!=nullptr){

            if(head==nullptr){
                head = new ListNode(current2->val);
                previous_node = head;
            }else{
                ListNode* node = new ListNode(current2->val);
                previous_node->next = node;
                previous_node = node;
                
            }

            current2 = current2->next;

        }


        return head;
    }
};
