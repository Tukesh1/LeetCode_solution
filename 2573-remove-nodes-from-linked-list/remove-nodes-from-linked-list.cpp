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
    ListNode* removeNodes(ListNode* head) {
        // base case
        if(head == NULL) return NULL;
        stack<ListNode*>st;
        ListNode *current = head;
        // push vales in stack
        while(current != NULL){
            st.push(current);
            current= current->next;
        }
         current= st.top();
         st.pop();
         int maxi= current->val;
        ListNode *result= new ListNode(current->val);
        while(!st.empty()){
            current = st.top();
            st.pop();
            if(current->val < maxi) continue;
            else{
                ListNode *newNode = new ListNode(current->val);
                newNode->next = result;
                result = newNode;
                maxi= current->val;
            }
        }
        return result;
    }
};