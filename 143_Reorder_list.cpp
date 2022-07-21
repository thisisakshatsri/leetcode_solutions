 void reorderList(ListNode* head) {
        //Find Middle of the Linked List
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //Reverse after Middle
        ListNode *prev = NULL;
        ListNode *curr = slow->next;
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow->next = NULL;
        
        //Arrage pointers
        ListNode *start = head;
        ListNode *end = prev;
        while(end){
            ListNode *temp = start->next;
            start->next = end;
            start = start->next;
            end = temp;
        }
    }