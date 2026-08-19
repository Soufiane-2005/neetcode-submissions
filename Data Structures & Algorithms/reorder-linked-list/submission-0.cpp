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

        stack<ListNode*> st;

        

        st.push(head);

        ListNode* left = head;
        ListNode* right;
        ListNode* temp;
        


        while(head->next){

            head = head->next;

            st.push(head);



        }


       


        while(left && !st.empty()){

            right = st.top();

           
            if(left==right){
                right->next = nullptr;
                break;
            }
           
            

            temp = left->next;
            left->next = right;
            left= temp;

            if(left==right){
                right->next = nullptr;
                break;
            }
           
            right->next = left;

           

            st.pop();
            



        }

        
    }
};
