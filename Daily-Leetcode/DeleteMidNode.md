# Slow and Fast Pointer
```
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        
        if(head == nullptr || head->next == nullptr)
            return nullptr;
            
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow=slow->next;
        }
        Node* temp = head;
        while(temp != nullptr)
        {
            if(temp->next == slow)
                break;
            temp = temp->next;
        }
        
        temp->next = slow->next;
        return head;
        
    }
};
```
