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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while(l1 && l2){
            int x = l1->val + l2->val;

            ListNode* node = new ListNode((x+carry)%10);

            curr->next = node;
            curr = node;

            carry = (x+carry)/10;

            l1=l1->next;
            l2=l2->next;
        }

        while(l1){

            int x = l1->val + carry;

            ListNode* node = new ListNode(x%10);

            curr->next = node;  
            curr = node;

            carry = x/10;

            l1 = l1->next;


        }
        while(l2){

            int x = l2->val + carry;

            ListNode* node = new ListNode(x%10);

            curr->next = node;  
            curr = node;

            carry = x/10;

            l2 = l2->next;


        }

        if(carry){
            ListNode* node = new ListNode(carry);

            curr->next = node;
            curr=node;
        }
        


        return dummy.next;










        
    }
};
