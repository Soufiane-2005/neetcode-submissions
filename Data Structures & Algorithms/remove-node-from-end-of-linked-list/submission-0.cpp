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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;

        ListNode* head1 = head;
        ListNode* head2 = head;

        while(head1){
            len++;
            head1=head1->next;
        }

        int position=len-n;

        cout<<position<<endl;

        if(position==0){
            return head->next;
        }

        ListNode* prv_node;
        ListNode* next_node=nullptr;

        while(head2){
            if(position==1){
                prv_node = head2;
            }
            if(position==-1){
                next_node=head2;
                break;
            }
            position--;
            head2 = head2->next;

        }

        prv_node->next=next_node;

        return head;


        
    }
};
