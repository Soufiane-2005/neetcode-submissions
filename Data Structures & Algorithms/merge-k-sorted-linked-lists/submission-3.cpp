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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        if(n==0){
            return nullptr;
        }else if(n==1){
            return lists[0];
        }else if(n==2){
            return merge2Lists(lists[0], lists[1]);
        } 

        
      
    


        while(n!=1){
        
            for(int i = 0; i<n ; i+=2){
                if(i==n-1){
                    lists[i/2]=lists[i];
                    continue;
                }
                lists[i/2] = merge2Lists(lists[i],lists[i+1]);
            }

            n = (n+1)/2;

        }
            
        return lists[0];
  

    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2){

        ListNode dummy;

        ListNode* curr = &dummy;

       
        int x;
        int y;
        while(l1 && l2){
            x = l1->val;
            y = l2->val;

           if(x<=y){
            curr->next = l1;
            curr = l1;
            l1=l1->next;
           }else{
            curr->next = l2;
            curr = l2;
            l2=l2->next;
           }

        }

        if(l1){
            curr->next = l1;
        }else if(l2){
            curr->next = l2;
        }



        return dummy.next;
    }
};
