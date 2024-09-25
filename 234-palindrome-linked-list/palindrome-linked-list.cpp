class Solution {
public:
    ListNode* reverse(ListNode* head) {

         ListNode* prev = NULL;
         ListNode* curr = head;

         while(curr) {
             
             ListNode* tmp = curr->next;
             curr->next = prev;
             prev = curr;
             curr = tmp;

         }

         return prev;
    }

    bool isPalindrome(ListNode* head) {
          
         ListNode* slow = head;
         ListNode* fast = head->next;

         while(fast && fast->next) {
             slow = slow->next;
             fast = fast->next->next;
         }  

         ListNode* agla = slow->next;
         slow->next = NULL;

         ListNode* newhead = reverse(agla);

         ListNode* first = head;
         ListNode* second = newhead;

         while(first && second) {
             if(first->val != second->val) return false;
             first = first->next;
             second = second->next;
         }
         
         return true;
    }
};