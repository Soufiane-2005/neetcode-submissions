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
    void reorderList(ListNode* head) {


       

        ListNode* slow=head;
        ListNode* fast=head;
    
        while(fast && fast->next){

            fast = fast->next->next;
            slow = slow->next;
            
        }

        ListNode* current= slow->next;
        slow->next = nullptr;

        ListNode* prv = nullptr;

        ListNode* next_node;
        

        while(current){

            next_node = current->next;
            current->next = prv;
            prv = current;
            current = next_node;
            
        }

        ListNode* right_head = prv;
        ListNode* left_head = head;

        ListNode* tempLeft;
        ListNode* tempRight;

        while(left_head && right_head){

            tempLeft = left_head->next;
            tempRight = right_head->next;
            left_head->next = right_head;
            right_head->next = tempLeft;
            left_head = tempLeft;
            right_head = tempRight;
            
        }






        
    }
};
