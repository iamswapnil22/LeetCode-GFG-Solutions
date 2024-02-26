
# [ReverseDLL](https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?page=1&category=Linked%20List&difficulty=Easy&status=unsolved&sortBy=submissions)

first node prev must null always
last node next must null always
first and last if equals stoo;
if first node prev == left which means it crossed by other node so stop and done
```
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if (head == nullptr) {
            return nullptr; // or handle as appropriate
        }

        Node* last = head;
        Node* first = head;
        // cout<<first->data<<"--";        
        while(last->next != nullptr)
        {
            last = last->next;
        }
        // cout<<last->data<<"--";
        while (first != nullptr && last != nullptr && first != last && first->prev != last) {
        
            int temp = first->data;
            // cout<<first->data<<"]-";
            first->data = last->data;
            last->data = temp;
            first = first->next;
            last = last->prev;
        }
        return head;
    }
};

```
