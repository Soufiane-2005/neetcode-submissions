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
    bool hasCycle(ListNode* head) {

        unordered_set<int> st;

        if(!head){
            return false;
        }

        while(head->next){
            if(st.contains(head->val)){
                return true;
            }else{
                st.insert(head->val);
            }

            head = head->next;     

        }

        return false;
        
    }
};
