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

    ListNode* reverseList(ListNode* head) {

        ListNode* result = nullptr;

        while(head!=nullptr){

            

            if(result==nullptr){
                result = new ListNode{head->val, nullptr};
            }else{

                ListNode* node = new ListNode{result->val, result->next};
                result->val = head->val;
                result->next = node;


            }

            head = head->next;

            

        }


        return result;

       

        


        
    }
};
