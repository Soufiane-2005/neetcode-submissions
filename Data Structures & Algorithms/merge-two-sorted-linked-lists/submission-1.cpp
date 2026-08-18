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

     

        ListNode* head = nullptr;

        ListNode* node ;

        while(list1!=nullptr && list2!=nullptr){
            if(head==nullptr){
                if(list1->val<=list2->val){
                    head = list1;
                    list1=list1->next;
                    head->next = list2;
                    node = head;
                }else{
                    head = list2;
                    list2=list2->next;
                    head->next = list1;
                    node = head;
                }
            }else{
                if(list1->val<=list2->val){
                    node->next = list1;
                    node = list1;
                    list1=list1->next;
                    
                }else{
                    node->next = list2;
                    node = list2;
                    list2=list2->next;
                }
            }
            
        }

        if(list1!=nullptr){
            if(head==nullptr){
                head=list1;
            }else{
                node->next = list1;
            }

        }else if(list2!=nullptr){
            if(head==nullptr){
                head = list2;
            }else{
                node->next = list2;
            }
        }

        

       

      


        return head;
    }
};
