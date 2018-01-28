class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        } else if (l2 == NULL){
            return l1;
        }

        ListNode* first;
        
        if(l1->val <= l2->val){
            first = l1;
            l1 = l1->next;
        } else{
            first = l2;
            l2 = l2->next;
        }
        first->next = NULL;
        ListNode* current = first;
        
        while(l1!=NULL && l2!= NULL){
        if(l1->val <= l2->val){
                current->next = l1;
                current = l1;
                l1 = l1->next;
            } else{
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
        }
        
        while(l1 != NULL){
            current->next = l1;
            current = l1;
            l1 = l1->next;
        }
        while(l2 != NULL){
            current->next = l2;
            current = l2;
            l2 = l2->next;
        }
        
        return first;
        
    }
};